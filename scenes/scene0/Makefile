ffmpeg:
	bash animate.sh scene0 5

render:
	rm *.png *.jpg *.mp4; \
	povray *.ini

update_environment:
	rsync -r -v /home/vngu/uni/ivc  grapefruit:/root/data/povray

render_on_server:
	rsync -r -v /home/vngu/uni/ivc/scenes/scene0/* grapefruit:/root/data/povray/ivc/scenes/scene0
	ssh grapefruit "cd /root/data/povray/ivc/scenes/scene0 && make render && make ffmpeg"
	rsync -r -v  grapefruit:/root/data/povray/ivc/scenes/scene0/*mp4 .
	vlc scene0_animation.mp4
