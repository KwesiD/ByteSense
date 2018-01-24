<h1>ByteSense</h1>

<h2>About</h2>
ByteSense is a project we (<a href="https://github.com/KwesiD">Kwesi Daniel</a> and <a href="https://github.com/deniskaydanov">Denis Kaydanov</a>) developed for our Expressive Cultures: Sounds class at New York University.

ByteSense is an Arduino-Uno-based musical instrument that generate MIDI notes based on sensor inputs.
The current sensors are:
1. IR Sensor
2. Sound Sensor
3. Photoresistor
4. Gyrosensor

The tempo is controlled by MIDI events determined by a potentiometer. 

ByteSense can work with any Digital Audio Workstation (DAW), but for the sake of the project, we worked with Abelton Live 9. 

<h2>Timing</h2>
Our implementation receives MIDI clock events from Ableton. <a href="https://en.wikipedia.org/wiki/MIDI_beat_clock"> Clock events are sent by Abelton at a rate of 24 pules per quarter note.</a> Each sensor sends its own note on a particular pulse number (ie: every 12th pulse for 8th notes).

<h2>Notes</h2>
Analog voltage values from the sensors are arbitrarily scaled and converted into MIDI notes.


<h2>Schematic</h2>
<img src="https://github.com/KwesiD/ByteSense/blob/master/ByteSense_bb.png?raw=true"></img>


<h2>Video</h2>
<blockquote class="instagram-media" data-instgrm-captioned data-instgrm-permalink="https://www.instagram.com/p/BcshAVxgNA7/" data-instgrm-version="8" style=" background:#FFF; border:0; border-radius:3px; box-shadow:0 0 1px 0 rgba(0,0,0,0.5),0 1px 10px 0 rgba(0,0,0,0.15); margin: 1px; max-width:658px; padding:0; width:99.375%; width:-webkit-calc(100% - 2px); width:calc(100% - 2px);"><div style="padding:8px;"> <div style=" background:#F8F8F8; line-height:0; margin-top:40px; padding:28.125% 0; text-align:center; width:100%;"> <div style=" background:url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACwAAAAsCAMAAAApWqozAAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAK7OHOkAAAAMUExURczMzPf399fX1+bm5mzY9AMAAADiSURBVDjLvZXbEsMgCES5/P8/t9FuRVCRmU73JWlzosgSIIZURCjo/ad+EQJJB4Hv8BFt+IDpQoCx1wjOSBFhh2XssxEIYn3ulI/6MNReE07UIWJEv8UEOWDS88LY97kqyTliJKKtuYBbruAyVh5wOHiXmpi5we58Ek028czwyuQdLKPG1Bkb4NnM+VeAnfHqn1k4+GPT6uGQcvu2h2OVuIf/gWUFyy8OWEpdyZSa3aVCqpVoVvzZZ2VTnn2wU8qzVjDDetO90GSy9mVLqtgYSy231MxrY6I2gGqjrTY0L8fxCxfCBbhWrsYYAAAAAElFTkSuQmCC); display:block; height:44px; margin:0 auto -44px; position:relative; top:-22px; width:44px;"></div></div> <p style=" margin:8px 0 0 0; padding:0 4px;"> <a href="https://www.instagram.com/p/BcshAVxgNA7/" style=" color:#000; font-family:Arial,sans-serif; font-size:14px; font-style:normal; font-weight:normal; line-height:17px; text-decoration:none; word-wrap:break-word;" target="_blank">Totally blown away by my students Denis and Kwesi in their #finalperformance yesterday. They built a sensor-instrument that responds to frequency, light and directionality. So much talent and ingenuity under our noses... feeling exceptionally lucky to be able to uncover it at the NYU music department!!!</a></p> <p style=" color:#c9c8cd; font-family:Arial,sans-serif; font-size:14px; line-height:17px; margin-bottom:0; margin-top:8px; overflow:hidden; padding:8px 0 7px; text-align:center; text-overflow:ellipsis; white-space:nowrap;">A post shared by <a href="https://www.instagram.com/aliceteyssier/" style=" color:#c9c8cd; font-family:Arial,sans-serif; font-size:14px; font-style:normal; font-weight:normal; line-height:17px;" target="_blank"> Alice Teyssier</a> (@aliceteyssier) on <time style=" font-family:Arial,sans-serif; font-size:14px; line-height:17px;" datetime="2017-12-14T20:10:16+00:00">Dec 14, 2017 at 12:10pm PST</time></p></div></blockquote> <script async defer src="//platform.instagram.com/en_US/embeds.js"></script>
