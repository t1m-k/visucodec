CC = emcc
CFLAGS = -O3 -Wall -Wextra

EMCC_FLAGS = \
	-s MODULARIZE=1 \
	-s EXPORT_ES6=1 \
	-s ENVIRONMENT='web' \
	-s EXPORTED_RUNTIME_METHODS="['ccall','cwrap','addFunction']" \
	-s ALLOW_MEMORY_GROWTH=1 \
	-s ALLOW_TABLE_GROWTH=1

THE_DIR = ./front/src/lib

SRCS = ./back/main.c
OBJS = $(SRCS:.c=.o)

.PHONY: all install run build clean

all:
	@echo "Available targets:"
	@echo "  make install  - compile C code into WASM + JS-glue"
	@echo "  make run      - run svelte dev server"
	@echo "  make build    - build for release"
	@echo "  make preview  - preview builded project"
	@echo "  make clean    - delete all generated files"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

install: $(OBJS)
	@mkdir -p $(THE_DIR)
	rm -f $(THE_DIR)/wasm.js $(THE_DIR)/wasm.wasm
	$(CC) $(CFLAGS) $(OBJS) -o $(THE_DIR)/wasm.js $(EMCC_FLAGS)
	@echo ""
	@echo "WASM was succesfuly compiled and installed to $(THE_DIR)"
	@echo ""

run:
	npm run dev --prefix front -- --host 0.0.0.0

build: install
	npm run build --prefix front

preview:
	npm run preview --prefix front -- --host 0.0.0.0

clean:
	rm -rf $(THE_DIR)/wasm.js $(THE_DIR)/wasm.wasm $(OBJS) ./dist
