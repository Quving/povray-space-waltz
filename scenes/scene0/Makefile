ffmpeg:
	ffmpeg -start_number 1 -i scene0%03d.png test.mp4
	# rm *png

render:
	rm *.png; \
	povray *.ini

update_environment:
	rsync -r -v /home/vngu/uni/ivc root@grapefruit:/root/data/povray

render_on_server:
	rsync -r -v /home/vngu/uni/ivc/scenes/scene0/* root@grapefruit:/root/data/povray/ivc/scenes/scene0
	ssh root@grapefruit.vingu.online "cd /root/data/povray/ivc/scenes/scene0 && make render && make ffmpeg"
	rsync -r -v  root@grapefruit.vingu.online:/root/data/povray/ivc/scenes/scene0/*mp4 .
