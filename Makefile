projectName = OpenGlTest

@all: ./builddir/$(projectName)

./builddir/$(projectName): ./builddir
	meson compile -C ./builddir

./builddir: meson.build
	meson setup builddir --reconfigure

clean:
	rm -r build

test: ./builddir/$(projectName)
	./test.sh

run: ./builddir/$(projectName)
	./builddir/$(projectName)
