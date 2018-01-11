

ffmpeg:
	bash animate.sh scene04 5
render:
	rm *.png *.jpg *.mp4; \
	    povray *.ini Final_Frame=50

# Render images and create mp4 file on server.
path_to_ivc=/home/vngu/ivc/scenes/scene04/
render_on_server:
	ssh grapefruit "cd ${path_to_ivc} && git reset --hard && git pull origin master" && \
	    rsync -r -v $(shell pwd)/* grapefruit:${path_to_ivc} && \
	    ssh grapefruit "cd ${path_to_ivc} && make render && make ffmpeg" && \
	    rsync -r -v  grapefruit:${path_to_ivc}*mp4 . && \
	    vlc scene04_animation.mp4
