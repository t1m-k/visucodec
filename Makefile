CC = emcc
CFLAGS = -O3 -Wall -Wextra

EMCC_FLAGS = \
	-s MODULARIZE=1 \
	-s EXPORT_ES6=1 \
	-s ENVIRONMENT='web' \
	-s EXPORTED_RUNTIME_METHODS="['ccall','cwrap','addFunction']" \
	-s ALLOW_MEMORY_GROWTH=1 \
	-s ALLOW_TABLE_GROWTH=1

TARGET_JS_DIR = ./front/src/lib
TARGET_JS     = $(TARGET_JS_DIR)/wasm.js
TARGET_WASM_DIR = ./front/public
TARGET_WASM   = $(TARGET_WASM_DIR)/wasm.wasm

SRCS = ./back/main.c
OBJS = $(SRCS:.c=.o)

.PHONY: all install run build clean

all:
	@echo "Available targets:"
	@echo "  make install  - compile C code into WASM"
	@echo "  make run      - run svelte"
	@echo "  make build    - npm run build"
	@echo "  make clean    - delete generated files"

install: $(OBJS)
	@mkdir -p $(TARGET_JS_DIR)
	@mkdir -p $(TARGET_WASM_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET_JS) $(EMCC_FLAGS)
	@if [ -f $(TARGET_JS_DIR)/wasm.wasm ]; then mv $(TARGET_JS_DIR)/wasm.wasm $(TARGET_WASM); fi
	@echo "WASM was succesfuly compiled and installed"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	cd front && npm run dev -- --host 0.0.0.0

build: install
	cd front && npm run build

clean:
	rm -rf $(TARGET_JS) $(TARGET_WASM) $(OBJS) ./front/dist
