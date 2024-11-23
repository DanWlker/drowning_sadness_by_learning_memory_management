build:
	zig cc -o out/helloworld -target aarch64-macos main.c

run: build
	./out/helloworld
