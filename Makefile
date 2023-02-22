CXX = g++
NUM_CORES = 32
CXXFLAGS = -g -O0 -Wall \
-I/usr/local/include \
-Isrc/bls/include \
-Isrc/bls/mcl/include \
-I/usr/local/lib \
-I/usr/local/include \
-I/usr/local/include
LDFLAGS= -lpthread
LIBMCL = libmcl.a
LIBBLS = libbls384_256.a
BLS_DIR = ./src/bls
LIBS = src/bls/lib/$(LIBBLS) src/bls/mcl/lib/$(LIBMCL)
OBJS = main.o mcl_wrapper.o
PROGRAM  = test
VPATH = src

all: $(PROGRAM)

$(PROGRAM): $(OBJS) $(LIBBLS) $(LIBMCL)
	$(CXX) $(OBJS) $(LIBS) $(LDFLAGS) -o $(PROGRAM)

$(LIBBLS): $(LIBMCL)
	make -j$(NUM_CORES) -C src/bls BLS_ETH=1 lib/$(LIBBLS)

$(LIBMCL): $(BLS_DIR)
	make -j$(NUM_CORES) -C src/bls/mcl lib/$(LIBMCL)

$(BLS_DIR):
	git clone --recursive https://github.com/herumi/bls $(BLS_DIR)

.SUFFIXES: .cpp .o
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	./$(PROGRAM)

clean:
	make -C src/bls/mcl clean
	make -C src/bls clean
	$(RM) $(PROGRAM)

clean-bls:
	$(RM) -r $(BLS_DIR)

.PHONY: run clean clean-bls