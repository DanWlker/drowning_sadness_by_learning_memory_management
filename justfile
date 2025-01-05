# Not sure if this is needed
# export ZIG_GLOBAL_CACHE_DIR="$PWD/cache" 
build-with-args args:
	export ZIG_LOCAL_CACHE_DIR="$PWD/out/cache" && \
	zig cc -o out/helloworld -target aarch64-macos main.c ./src/*.c {{args}}

build: (build-with-args "")

run: build
	./out/helloworld

build-verbose: (build-with-args "--verbose")
