# Variables
SCENE_NAME = $(shell pwd | sed -e "s/.*\///g")
PATH_TO_SCENE= $(shell pwd)

ffmpeg:
	bash animate.sh ${SCENE_NAME} 5
render:
	rm *.png *.jpg *.mp4; \
	    povray *.ini Final_Frame=1

# Render images and create mp4 file on server.
render_on_server:
	ssh grapefruit "cd ${PATH_TO_SCENE} && git reset --hard && git pull origin master" && \
	    rsync -r -v $(shell pwd)/* grapefruit:${PATH_TO_SCENE} && \
	    ssh grapefruit "cd ${PATH_TO_SCENE} && make render && make ffmpeg" && \
	    rsync -r -v  grapefruit:${PATH_TO_SCENE}*mp4 . && \
	    vlc ${SCENE_NAME}_animation.mp4
