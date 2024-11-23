build-with-args args:
	zig cc -o out/helloworld -target aarch64-macos main.c ./src/*.c {{args}}

build: (build-with-args "")

run: build
	./out/helloworld

build-verbose: (build-with-args "--verbose")
