ffmpeg:
	ffmpeg -start_number 1 -i test1%03d.png test.mp4

render:
	povray test.ini
	povray test-xy.ini

clean:
	rm *.png *.mp4
