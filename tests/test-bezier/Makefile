ffmpeg:
	ffmpeg -start_number 1 -i test1%03d.png test.mp4
	# rm *png

render:
	povray test-bezier.ini

clean:
	rm *.png

spline-demo:
	povray +L/usr/share/fonts/steam-fonts spline_demo.pov
