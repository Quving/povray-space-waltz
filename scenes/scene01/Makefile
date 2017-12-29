ffmpeg:
	bash animate.sh scene01 13

render:
	rm *.png *.jpg *.mp4; \
	povray *.ini Final_Frame=500

update_environment:
	rsync -r -v /home/vngu/uni/ivc  grapefruit:/root/data/povray

render_on_server:
	rsync -r -v /home/vngu/uni/ivc/scenes/scene01/* grapefruit:/root/data/povray/ivc/scenes/scene01
	ssh grapefruit "cd /root/data/povray/ivc/scenes/scene01 && make render && make ffmpeg"
	rsync -r -v  grapefruit:/root/data/povray/ivc/scenes/scene01/*mp4 .
	vlc scene01_animation.mp4
