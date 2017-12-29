ffmpeg:
	bash animate.sh scene02 5

render:
	rm *.png *.jpg *.mp4; \
	povray *.ini Final_Frame=500

update_environment:
	rsync -r -v /home/vngu/uni/ivc  grapefruit:/root/data/povray

render_on_server:
	rsync -r -v /home/vngu/uni/ivc/scenes/scene02/* grapefruit:/root/data/povray/ivc/scenes/scene02
	ssh grapefruit "cd /root/data/povray/ivc/scenes/scene02 && make render && make ffmpeg"
	rsync -r -v  grapefruit:/root/data/povray/ivc/scenes/scene02/*mp4 .
	vlc scene02_animation.mp4
