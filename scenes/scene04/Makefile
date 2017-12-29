ffmpeg:
	bash animate.sh scene04 5
render:
	rm *.png *.jpg *.mp4; \
	    povray *.ini Final_Frame=50
render_on_server:
	ssh grapefruit "cd /root/data/povray/ivc/scenes/scene04 && git reset --hard && git pull origin master" && \
	    rsync -r -v $(shell pwd)/* grapefruit:/root/data/povray/ivc/scenes/scene04 && \
	    ssh grapefruit "cd /root/data/povray/ivc/scenes/scene04 && make render && make ffmpeg" && \
	    rsync -r -v  grapefruit:/root/data/povray/ivc/scenes/scene04/*mp4 . && \
	    vlc scene04_animation.mp4
