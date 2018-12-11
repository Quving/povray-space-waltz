# Povray Space Waltz
This repository arises in scope of a project at the university. The scripts are written in [povray](http://www.povray.org/) and the scenes are inspired by the video shown below.

[![](http://img.youtube.com/vi/bmVO12sePDU/3.jpg)](https://youtu.be/bmVO12sePDU)
### Result

[Movie](https://www.dropbox.com/s/rhwbxh6xsowv4h8/Povray-Space-Waltz.mp4?dl=0)

### Materials
**Frames**
Can be found [here](http://nextcloud.quving.com/s/Rz0sMC3ukrKEVI0) (Nextcloud).

**Rendering results**
Can be found [here](https://www.dropbox.com/sh/xzp3uizmcah1yaf/AAC9UrARoHbLAg4TAS3cS37Oa?dl=0) (Dropbox).

### Scenes
- [Scene  1](https://www.youtube.com/embed/xyjOjT8d8RI?start=0&end=13)    : Kamera schwenkt von Bombe zu Planet
- [Scene  2](https://www.youtube.com/embed/xyjOjT8d8RI?start=13&end=23)   : Planet links, Bombe rechts im Bild
- [Scene  3](https://www.youtube.com/embed/xyjOjT8d8RI?start=23&end=31)   : Planet halb vor Sonne, Bombe fliegt ins Bild
- [Scene  4](https://www.youtube.com/embed/xyjOjT8d8RI?start=31&end=56)   : Kamera schwenkt von Planet ins All zu Bombe und auf anderen Planeten
- [Scene  5](https://www.youtube.com/embed/xyjOjT8d8RI?start=56&end=85)   : Kamera fliegt an drehende Station heran, Planet kurz rechts im Bild
- [Scene  6](https://www.youtube.com/embed/xyjOjT8d8RI?start=85&end=105)  : Kamera schwenkt von Planet (links unten) zur Orion
- [Scene  7](https://www.youtube.com/embed/xyjOjT8d8RI?start=105&end=124) : Innenraum Orion, Passagier von hinten, Hand bewegt sich, Stift schwebt durchs Bild
- [Scene  8](https://www.youtube.com/embed/xyjOjT8d8RI?start=124&end=132) : Innenraum Orion, Blickwechsel auf Passagier von Schrägvorne
- [Scene  9](https://www.youtube.com/embed/xyjOjT8d8RI?start=132&end=142) : Innenraum Orion, Fokus auf schwebendem Stift vor unscharfen Hintergrund; Tür öffnet sich und Fokus wechselt auf den Hintergrund, Flugbegleiterin kommt durch Tür und schließt sie wieder
- [Scene 10](https://www.youtube.com/embed/xyjOjT8d8RI?start=142&end=148) : Innenraum Orion, Füße und Schuhe der Flugbegleiterin im Bild, macht unsichere Schritte
- [Scene 11](https://www.youtube.com/embed/xyjOjT8d8RI?start=148&end=165) : Innenraum Orion, Flugbegleiterin bewegt sich vorsichtig von der Tür auf den Stift zu, Kamera bewegt sich rückwärts; sie kommt beim Stift an und greift ihn
- [Scene 12](https://www.youtube.com/embed/xyjOjT8d8RI?start=165&end=175) : Innenraum Orion, Flugbegleiterin steckt Stift in Brusttasche des Passagiers und bewegt sich aus dem Bild
- [Scene 13](https://www.youtube.com/embed/xyjOjT8d8RI?start=175&end=182) : von Links nach Rechts Orion, Station und Planet im Bild, Orion fliegt Richtung Station
- [Scene 14](https://www.youtube.com/embed/xyjOjT8d8RI?start=182&end=211) : Planet links, Station kommt von rechts in Bild, Orion fliegt von unten an die Station heran.
- [Scene 15](https://www.youtube.com/embed/xyjOjT8d8RI?start=211&end=221) : Innenansicht Orion, Cockpit: Piloten links und rechts von hinten zu sehen, sowie Instrumente im Cockpit, Station durch Frontscheibe vor dem Schiff zu sehen
- [Scene 16](https://www.youtube.com/embed/xyjOjT8d8RI?start=221&end=228) : Innenansicht Orion, Cockpit: Nahaufnahme Instrumente
- [Scene 17](https://www.youtube.com/embed/xyjOjT8d8RI?start=228&end=270) : Innenansicht Station, Hangar: Kamera blickt ins All und bewegt sich rückwärts; Orion kommt vor Hangaröffnung ins Bild
- [Scene 18](https://www.youtube.com/embed/xyjOjT8d8RI?start=270&end=289) : Orion links, Station rechts, beide drehen sich, Orion synchronisiert Drehung um die Längsachse mit Station
- [Scene 19](https://www.youtube.com/embed/xyjOjT8d8RI?start=289&end=300) : Innenansicht Orion, Cockpit: Station richtig ausgerichtet direkt vor Frontscheibe, Orion im Anflug
- [Scene 20](https://www.youtube.com/embed/xyjOjT8d8RI?start=300&end=321) : Orion direkt vor Hangar; Kamera fliegt nah an der Station vorbei bis Station außer Sicht

#### ordered by setting

Weltraum (223s): 1, 2, 3, 4, 5, 6, 13, 14, 17, 18, 20
Orion Passagierraum (komplexe Animation) (70s): 7, 8, 9, 10, 11, 12
Orion Cockpit (28s): 15, 16, 19


### Commands

#### Render frames (Video is runnable on Linux and Windows)
```
ffmpeg -r 60 -start_number 1 -i scene19%03d.png -c:v libx264 \
-strict experimental -tune fastdecode -pix_fmt yuv420p -b:v 1500k out.mp4

```

### Important

- Credit the creator of the models
- Soundtrack?

## Ressources

### Models

- [2001 3D Archive](http://www.2001-3d-archive.info/)

### Animation

- [Objects, which rotate around other objects](http://www.f-lohmueller.de/pov_tut/animate/anim112e.htm)
- Nonlinear Animations
  - [Speed up and slow down (1)](http://www.f-lohmueller.de/pov_tut/animate/anim220e.htm)
  - [Speed up and slow down (2)](http://www.f-lohmueller.de/pov_tut/animate/anim222e.htm)
  - [Speed controll by spline functions](http://www.f-lohmueller.de/pov_tut/animate/anim280e.htm)
- Animation Paths
  - [Spline curves](http://www.f-lohmueller.de/pov_tut/animate/anim210e.htm)
  - [Closed splines](http://www.f-lohmueller.de/pov_tut/animate/anim21e.htm)
  - [Animation paths](http://www.f-lohmueller.de/pov_tut/animate/anim22e.htm)


## Snippets

- [Planets](http://www.midnightkite.com/index.aspx?URL=PlanetRendering)
