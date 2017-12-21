PWD_WO_HOME = $(shell pwd | sed -e "s/\/home\/[a-z]*\///g")
SCENE_NAME = $(shell pwd | sed -e "s/.*\///g")

ffmpeg:
	bash animate.sh $(SCENE_NAME) 6

render:
	povray *.ini

update_environment:
	rsync -r -v \
		--cvs-exclude \
		--exclude="scenes/*/*.png" \
		--exclude="slides/" \
		--exclude="*.mp4" \
		../../  grapefruit:ivc/

render_on_server:
	rsync -r -v . grapefruit:ivc/scenes/
	ssh grapefruit "cd ivc/scenes/$(SCENE_NAME) && make render && make ffmpeg"
	rsync -r -v  grapefruit:$(PWD_WO_HOME)/*.mp4 .

test:
	povray $(SCENE_NAME).ini

clean:
	rm *.png

foo:
	echo $(PWD_WO_HOME)
	echo $(SCENE_NAME)
