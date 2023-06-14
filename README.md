# Dual-button doorbell

Project is under construction. Errors are very lightly to occur at this stage. Custom symbols, footprints and 3D models can be found in [espena/kicad-libs](https://github.com/espena/kicad-libs) whenever they're ready.

A door bell that simply does more. Configurable with alarms, different sounds for the two buttons, bedtime LED indicator and timed notifications on specific days / hours. With audible 4Ω loudspeaker driven by a class D 3.2 W amplifier.

## Planned features

- Two-button interface with red/green indicators
- Personalized doorbell sound from custom wav files
- SD card support for storing audio files and configuration
- WiFi interface for push notifications and remote configuration
- NTP corrected Real time clock for alarms and bedtime signal
- Volume reduction during bedtime
- Relay interface for triggering external equipment

## Circuit

![PCB layout](/gfx/pcb_rendering.png?raw=true "PCB rendering")

![Circuit schematics](/gfx/schematics.png?raw=true "Circuit schematics")

## Button panel

![Button panel design](/gfx/button_panel_finish.jpg?raw=true "Button panel finished design")

## Panel back side enclosure

```stl
solid Mesh
  facet normal 0.000000 1.000000 0.000000
    outer loop
      vertex 50.000000 30.000000 0.000000
      vertex -50.000000 30.000000 0.000000
      vertex -50.000000 30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 1.000000 -0.000000
    outer loop
      vertex 50.000000 30.000000 0.000000
      vertex -50.000000 30.000000 19.000000
      vertex 50.000000 30.000000 19.000000
    endloop
  endfacet
  facet normal -1.000000 -0.000000 0.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -50.000000 -30.000000 0.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal -1.000000 0.000000 0.000000
    outer loop
      vertex -50.000000 30.000000 0.000000
      vertex -50.000000 -30.000000 0.000000
      vertex -50.000000 30.000000 19.000000
    endloop
  endfacet
  facet normal 1.000000 -0.000000 0.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 50.000000 30.000000 0.000000
      vertex 50.000000 30.000000 19.000000
    endloop
  endfacet
  facet normal 1.000000 0.000000 0.000000
    outer loop
      vertex 50.000000 -30.000000 0.000000
      vertex 50.000000 30.000000 0.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 0.000000
      vertex -50.000000 30.000000 0.000000
      vertex -48.000000 28.000000 0.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -50.000000 -30.000000 0.000000
      vertex -50.000000 30.000000 0.000000
      vertex -48.000000 -28.000000 0.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -50.000000 -30.000000 0.000000
      vertex 48.000000 -28.000000 0.000000
      vertex 50.000000 -30.000000 0.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 0.000000
      vertex 48.000000 -28.000000 0.000000
      vertex -50.000000 -30.000000 0.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 48.000000 28.000000 0.000000
      vertex 50.000000 30.000000 0.000000
      vertex 48.000000 -28.000000 0.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 48.000000 -28.000000 0.000000
      vertex 50.000000 30.000000 0.000000
      vertex 50.000000 -30.000000 0.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -50.000000 30.000000 0.000000
      vertex 50.000000 30.000000 0.000000
      vertex -48.000000 28.000000 0.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 0.000000
      vertex 50.000000 30.000000 0.000000
      vertex 48.000000 28.000000 0.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -29.796875 -7.549917 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -29.410429 -7.946122 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -29.004713 -8.322572 19.000000
      vertex -29.410429 -7.946122 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -30.163094 -7.134943 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -29.796875 -7.549917 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -28.580736 -8.678329 19.000000
      vertex -29.004713 -8.322572 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -30.508171 -6.702229 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -30.163094 -7.134943 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -28.139555 -9.012512 19.000000
      vertex -28.580736 -8.678329 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -30.831251 -6.252852 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -30.508171 -6.702229 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -27.682264 -9.324287 19.000000
      vertex -28.139555 -9.012512 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -31.131529 -5.787931 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -30.831251 -6.252852 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -27.209999 -9.612882 19.000000
      vertex -27.682264 -9.324287 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -31.408260 -5.308619 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -31.131529 -5.787931 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -26.723938 -9.877577 19.000000
      vertex -27.209999 -9.612882 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -31.660755 -4.816110 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -31.408260 -5.308619 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -26.225286 -10.117715 19.000000
      vertex -26.723938 -9.877577 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -31.888386 -4.311626 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -31.660755 -4.816110 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -25.715286 -10.332699 19.000000
      vertex -26.225286 -10.117715 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -32.090588 -3.796424 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -31.888386 -4.311626 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -25.195202 -10.521994 19.000000
      vertex -25.715286 -10.332699 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -32.266857 -3.271782 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -32.090588 -3.796424 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -24.666328 -10.685129 19.000000
      vertex -25.195202 -10.521994 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -32.416759 -2.739007 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -32.266857 -3.271782 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -24.129982 -10.821700 19.000000
      vertex -24.666328 -10.685129 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -32.539913 -2.199422 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -32.416759 -2.739007 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -23.587494 -10.931366 19.000000
      vertex -24.129982 -10.821700 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -32.636021 -1.654369 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -32.539913 -2.199422 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -23.040215 -11.013855 19.000000
      vertex -23.587494 -10.931366 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -32.704842 -1.105203 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -32.636021 -1.654369 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -22.489504 -11.068962 19.000000
      vertex -23.040215 -11.013855 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -32.746201 -0.553289 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -32.704842 -1.105203 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -21.936731 -11.096550 19.000000
      vertex -22.489504 -11.068962 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -32.759998 0.000000 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -32.746201 -0.553289 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -21.383270 -11.096550 19.000000
      vertex -21.936731 -11.096550 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -20.830496 -11.068962 19.000000
      vertex -21.383270 -11.096550 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -20.279785 -11.013855 19.000000
      vertex -20.830496 -11.068962 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -19.732506 -10.931366 19.000000
      vertex -20.279785 -11.013855 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -19.190018 -10.821700 19.000000
      vertex -19.732506 -10.931366 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -18.653671 -10.685129 19.000000
      vertex -19.190018 -10.821700 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -50.000000 -30.000000 19.000000
      vertex -32.759998 0.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -32.759998 0.000000 19.000000
      vertex -32.746201 0.553289 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -32.746201 0.553289 19.000000
      vertex -32.704842 1.105203 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -32.704842 1.105203 19.000000
      vertex -32.636021 1.654369 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -32.636021 1.654369 19.000000
      vertex -32.539913 2.199422 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -32.539913 2.199422 19.000000
      vertex -32.416759 2.739007 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -32.416759 2.739007 19.000000
      vertex -32.266857 3.271782 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -32.266857 3.271782 19.000000
      vertex -32.090588 3.796424 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -32.090588 3.796424 19.000000
      vertex -31.888386 4.311626 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -31.888386 4.311626 19.000000
      vertex -31.660755 4.816110 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -31.660755 4.816110 19.000000
      vertex -31.408260 5.308619 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -31.408260 5.308619 19.000000
      vertex -31.131529 5.787931 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -31.131529 5.787931 19.000000
      vertex -30.831251 6.252852 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -30.831251 6.252852 19.000000
      vertex -30.508171 6.702229 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -30.508171 6.702229 19.000000
      vertex -30.163094 7.134943 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -30.163094 7.134943 19.000000
      vertex -29.796875 7.549917 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -29.796875 7.549917 19.000000
      vertex -29.410429 7.946122 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -50.000000 30.000000 19.000000
      vertex -29.410429 7.946122 19.000000
      vertex -29.004713 8.322572 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -28.580736 8.678329 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -29.004713 8.322572 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -28.139555 9.012512 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -28.580736 8.678329 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -27.682264 9.324287 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -28.139555 9.012512 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -27.209999 9.612882 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -27.682264 9.324287 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -26.723938 9.877577 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -27.209999 9.612882 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -26.225286 10.117715 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -26.723938 9.877577 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -25.715286 10.332699 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -26.225286 10.117715 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -25.195202 10.521994 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -25.715286 10.332699 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -24.666328 10.685129 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -25.195202 10.521994 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -24.129982 10.821700 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -24.666328 10.685129 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -23.587494 10.931366 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -24.129982 10.821700 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -23.040215 11.013855 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -23.587494 10.931366 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -22.489504 11.068962 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -23.040215 11.013855 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -21.936731 11.096550 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -22.489504 11.068962 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -21.383270 11.096550 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -21.936731 11.096550 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -20.830496 11.068962 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -21.383270 11.096550 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -20.279785 11.013855 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -20.830496 11.068962 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -19.732506 10.931366 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -20.279785 11.013855 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -19.190018 10.821700 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -19.732506 10.931366 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 13.522124 -7.549917 19.000000
      vertex -13.909572 -7.946122 19.000000
      vertex 13.908571 -7.946122 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 13.522124 -7.549917 19.000000
      vertex -13.523125 -7.549917 19.000000
      vertex -13.909572 -7.946122 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 14.314287 -8.322572 19.000000
      vertex 13.908571 -7.946122 19.000000
      vertex -13.909572 -7.946122 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 14.314287 -8.322572 19.000000
      vertex -13.909572 -7.946122 19.000000
      vertex -14.315288 -8.322572 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 14.314287 -8.322572 19.000000
      vertex -14.315288 -8.322572 19.000000
      vertex -14.739264 -8.678329 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 13.155907 -7.134943 19.000000
      vertex -12.811830 -6.702229 19.000000
      vertex -13.156907 -7.134943 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 13.155907 -7.134943 19.000000
      vertex -13.156907 -7.134943 19.000000
      vertex -13.523125 -7.549917 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 13.155907 -7.134943 19.000000
      vertex -13.523125 -7.549917 19.000000
      vertex 13.522124 -7.549917 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 14.738263 -8.678329 19.000000
      vertex 14.314287 -8.322572 19.000000
      vertex -14.739264 -8.678329 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.810829 -6.702229 19.000000
      vertex -12.811830 -6.702229 19.000000
      vertex 13.155907 -7.134943 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 15.179445 -9.012512 19.000000
      vertex -14.739264 -8.678329 19.000000
      vertex -15.180446 -9.012512 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 15.179445 -9.012512 19.000000
      vertex -15.180446 -9.012512 19.000000
      vertex -15.637736 -9.324287 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 15.179445 -9.012512 19.000000
      vertex 14.738263 -8.678329 19.000000
      vertex -14.739264 -8.678329 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.487750 -6.252852 19.000000
      vertex -12.488750 -6.252852 19.000000
      vertex -12.811830 -6.702229 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.487750 -6.252852 19.000000
      vertex -12.811830 -6.702229 19.000000
      vertex 12.810829 -6.702229 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 15.636737 -9.324287 19.000000
      vertex 15.179445 -9.012512 19.000000
      vertex -15.637736 -9.324287 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.187471 -5.787931 19.000000
      vertex -11.911740 -5.308619 19.000000
      vertex -12.188471 -5.787931 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.187471 -5.787931 19.000000
      vertex -12.188471 -5.787931 19.000000
      vertex -12.488750 -6.252852 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.187471 -5.787931 19.000000
      vertex -12.488750 -6.252852 19.000000
      vertex 12.487750 -6.252852 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 16.108999 -9.612882 19.000000
      vertex -15.637736 -9.324287 19.000000
      vertex -16.110001 -9.612882 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 16.108999 -9.612882 19.000000
      vertex 15.636737 -9.324287 19.000000
      vertex -15.637736 -9.324287 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.910741 -5.308619 19.000000
      vertex -11.911740 -5.308619 19.000000
      vertex 12.187471 -5.787931 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 16.595062 -9.877577 19.000000
      vertex 16.108999 -9.612882 19.000000
      vertex -16.110001 -9.612882 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 16.595062 -9.877577 19.000000
      vertex -16.110001 -9.612882 19.000000
      vertex -16.596062 -9.877577 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.658246 -4.816110 19.000000
      vertex -11.659245 -4.816110 19.000000
      vertex -11.911740 -5.308619 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.658246 -4.816110 19.000000
      vertex -11.911740 -5.308619 19.000000
      vertex 11.910741 -5.308619 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 17.093714 -10.117715 19.000000
      vertex -16.596062 -9.877577 19.000000
      vertex -17.094713 -10.117715 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 17.093714 -10.117715 19.000000
      vertex 16.595062 -9.877577 19.000000
      vertex -16.596062 -9.877577 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.430614 -4.311626 19.000000
      vertex -11.431614 -4.311626 19.000000
      vertex -11.659245 -4.816110 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.430614 -4.311626 19.000000
      vertex -11.659245 -4.816110 19.000000
      vertex 11.658246 -4.816110 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 17.603714 -10.332699 19.000000
      vertex -17.094713 -10.117715 19.000000
      vertex -17.604715 -10.332699 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 17.603714 -10.332699 19.000000
      vertex 17.093714 -10.117715 19.000000
      vertex -17.094713 -10.117715 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.228412 -3.796424 19.000000
      vertex -11.053142 -3.271782 19.000000
      vertex -11.229412 -3.796424 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.228412 -3.796424 19.000000
      vertex -11.229412 -3.796424 19.000000
      vertex -11.431614 -4.311626 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.228412 -3.796424 19.000000
      vertex -11.431614 -4.311626 19.000000
      vertex 11.430614 -4.311626 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 18.123798 -10.521994 19.000000
      vertex -17.604715 -10.332699 19.000000
      vertex -18.124798 -10.521994 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 18.123798 -10.521994 19.000000
      vertex 17.603714 -10.332699 19.000000
      vertex -17.604715 -10.332699 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.052142 -3.271782 19.000000
      vertex -11.053142 -3.271782 19.000000
      vertex 11.228412 -3.796424 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 18.652670 -10.685129 19.000000
      vertex -18.124798 -10.521994 19.000000
      vertex -18.653671 -10.685129 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 18.652670 -10.685129 19.000000
      vertex -18.653671 -10.685129 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 18.652670 -10.685129 19.000000
      vertex 18.123798 -10.521994 19.000000
      vertex -18.124798 -10.521994 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.902242 -2.739007 19.000000
      vertex -10.903242 -2.739007 19.000000
      vertex -11.053142 -3.271782 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.902242 -2.739007 19.000000
      vertex -11.053142 -3.271782 19.000000
      vertex 11.052142 -3.271782 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.779085 -2.199422 19.000000
      vertex -10.780086 -2.199422 19.000000
      vertex -10.903242 -2.739007 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.779085 -2.199422 19.000000
      vertex -10.903242 -2.739007 19.000000
      vertex 10.902242 -2.739007 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.682978 -1.654369 19.000000
      vertex -10.683978 -1.654369 19.000000
      vertex -10.780086 -2.199422 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.682978 -1.654369 19.000000
      vertex -10.780086 -2.199422 19.000000
      vertex 10.779085 -2.199422 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.614159 -1.105203 19.000000
      vertex -10.573798 -0.553289 19.000000
      vertex -10.615158 -1.105203 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.614159 -1.105203 19.000000
      vertex -10.615158 -1.105203 19.000000
      vertex -10.683978 -1.654369 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.614159 -1.105203 19.000000
      vertex -10.683978 -1.654369 19.000000
      vertex 10.682978 -1.654369 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.572798 -0.553289 19.000000
      vertex -10.573798 -0.553289 19.000000
      vertex 10.614159 -1.105203 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.559000 0.000000 19.000000
      vertex -10.573798 -0.553289 19.000000
      vertex 10.572798 -0.553289 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.559000 0.000000 19.000000
      vertex -10.560000 0.000000 19.000000
      vertex -10.573798 -0.553289 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.572798 0.553289 19.000000
      vertex -10.573798 0.553289 19.000000
      vertex -10.560000 0.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.572798 0.553289 19.000000
      vertex -10.560000 0.000000 19.000000
      vertex 10.559000 0.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.614159 1.105203 19.000000
      vertex -10.683978 1.654369 19.000000
      vertex -10.615158 1.105203 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.614159 1.105203 19.000000
      vertex -10.615158 1.105203 19.000000
      vertex -10.573798 0.553289 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.614159 1.105203 19.000000
      vertex -10.573798 0.553289 19.000000
      vertex 10.572798 0.553289 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.682978 1.654369 19.000000
      vertex -10.683978 1.654369 19.000000
      vertex 10.614159 1.105203 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.682978 1.654369 19.000000
      vertex -10.780086 2.199422 19.000000
      vertex -10.683978 1.654369 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.779085 2.199422 19.000000
      vertex -10.903242 2.739007 19.000000
      vertex -10.780086 2.199422 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.779085 2.199422 19.000000
      vertex -10.780086 2.199422 19.000000
      vertex 10.682978 1.654369 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.902242 2.739007 19.000000
      vertex -10.903242 2.739007 19.000000
      vertex 10.779085 2.199422 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 10.902242 2.739007 19.000000
      vertex -11.053142 3.271782 19.000000
      vertex -10.903242 2.739007 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.052142 3.271782 19.000000
      vertex -11.229412 3.796424 19.000000
      vertex -11.053142 3.271782 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.052142 3.271782 19.000000
      vertex -11.053142 3.271782 19.000000
      vertex 10.902242 2.739007 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.228412 3.796424 19.000000
      vertex -11.431614 4.311626 19.000000
      vertex -11.229412 3.796424 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.228412 3.796424 19.000000
      vertex -11.229412 3.796424 19.000000
      vertex 11.052142 3.271782 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.430614 4.311626 19.000000
      vertex -11.659245 4.816110 19.000000
      vertex -11.431614 4.311626 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.430614 4.311626 19.000000
      vertex -11.431614 4.311626 19.000000
      vertex 11.228412 3.796424 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.658246 4.816110 19.000000
      vertex -11.911740 5.308619 19.000000
      vertex -11.659245 4.816110 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.658246 4.816110 19.000000
      vertex -11.659245 4.816110 19.000000
      vertex 11.430614 4.311626 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 11.910741 5.308619 19.000000
      vertex -11.911740 5.308619 19.000000
      vertex 11.658246 4.816110 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.187471 5.787931 19.000000
      vertex -11.911740 5.308619 19.000000
      vertex 11.910741 5.308619 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.187471 5.787931 19.000000
      vertex -12.488750 6.252852 19.000000
      vertex -12.188471 5.787931 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.187471 5.787931 19.000000
      vertex -12.188471 5.787931 19.000000
      vertex -11.911740 5.308619 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.487750 6.252852 19.000000
      vertex -12.488750 6.252852 19.000000
      vertex 12.187471 5.787931 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.810829 6.702229 19.000000
      vertex -13.156907 7.134943 19.000000
      vertex -12.811830 6.702229 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.810829 6.702229 19.000000
      vertex -12.811830 6.702229 19.000000
      vertex -12.488750 6.252852 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 12.810829 6.702229 19.000000
      vertex -12.488750 6.252852 19.000000
      vertex 12.487750 6.252852 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 18.652670 -10.685129 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 28.579737 -8.678329 19.000000
      vertex 28.138556 -9.012512 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 28.138556 -9.012512 19.000000
      vertex 27.681263 -9.324287 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 27.681263 -9.324287 19.000000
      vertex 27.209000 -9.612882 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 27.209000 -9.612882 19.000000
      vertex 26.722939 -9.877577 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 26.722939 -9.877577 19.000000
      vertex 26.224287 -10.117715 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 26.224287 -10.117715 19.000000
      vertex 25.714285 -10.332699 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 25.714285 -10.332699 19.000000
      vertex 25.194202 -10.521994 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 25.194202 -10.521994 19.000000
      vertex 24.665329 -10.685129 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 24.665329 -10.685129 19.000000
      vertex 24.128983 -10.821700 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 24.128983 -10.821700 19.000000
      vertex 23.586494 -10.931366 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 23.586494 -10.931366 19.000000
      vertex 23.039215 -11.013855 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 23.039215 -11.013855 19.000000
      vertex 22.488504 -11.068962 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 22.488504 -11.068962 19.000000
      vertex 21.935730 -11.096550 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 21.935730 -11.096550 19.000000
      vertex 21.382269 -11.096550 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 21.382269 -11.096550 19.000000
      vertex 20.829496 -11.068962 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 20.829496 -11.068962 19.000000
      vertex 20.278786 -11.013855 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 20.278786 -11.013855 19.000000
      vertex 19.731504 -10.931366 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 19.731504 -10.931366 19.000000
      vertex 19.189018 -10.821700 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 -30.000000 19.000000
      vertex 19.189018 -10.821700 19.000000
      vertex 18.652670 -10.685129 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 13.155907 7.134943 19.000000
      vertex -13.156907 7.134943 19.000000
      vertex 12.810829 6.702229 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 13.155907 7.134943 19.000000
      vertex -13.523125 7.549917 19.000000
      vertex -13.156907 7.134943 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 29.003714 -8.322572 19.000000
      vertex 28.579737 -8.678329 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 13.522124 7.549917 19.000000
      vertex -13.523125 7.549917 19.000000
      vertex 13.155907 7.134943 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 29.409430 -7.946122 19.000000
      vertex 29.003714 -8.322572 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 13.908571 7.946122 19.000000
      vertex -14.315288 8.322572 19.000000
      vertex -13.909572 7.946122 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 13.908571 7.946122 19.000000
      vertex -13.909572 7.946122 19.000000
      vertex -13.523125 7.549917 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 13.908571 7.946122 19.000000
      vertex -13.523125 7.549917 19.000000
      vertex 13.522124 7.549917 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 29.795876 -7.549917 19.000000
      vertex 29.409430 -7.946122 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 14.314287 8.322572 19.000000
      vertex -14.315288 8.322572 19.000000
      vertex 13.908571 7.946122 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 30.162094 -7.134943 19.000000
      vertex 29.795876 -7.549917 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 14.738263 8.678329 19.000000
      vertex -14.739264 8.678329 19.000000
      vertex -14.315288 8.322572 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 14.738263 8.678329 19.000000
      vertex -14.315288 8.322572 19.000000
      vertex 14.314287 8.322572 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 30.507172 -6.702229 19.000000
      vertex 30.162094 -7.134943 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 15.179445 9.012512 19.000000
      vertex -15.637736 9.324287 19.000000
      vertex -15.180446 9.012512 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 15.179445 9.012512 19.000000
      vertex -15.180446 9.012512 19.000000
      vertex -14.739264 8.678329 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 15.179445 9.012512 19.000000
      vertex -14.739264 8.678329 19.000000
      vertex 14.738263 8.678329 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 30.830250 -6.252852 19.000000
      vertex 30.507172 -6.702229 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 15.636737 9.324287 19.000000
      vertex -16.110001 9.612882 19.000000
      vertex -15.637736 9.324287 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 15.636737 9.324287 19.000000
      vertex -15.637736 9.324287 19.000000
      vertex 15.179445 9.012512 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 31.130529 -5.787931 19.000000
      vertex 30.830250 -6.252852 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 16.108999 9.612882 19.000000
      vertex -16.596062 9.877577 19.000000
      vertex -16.110001 9.612882 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 16.108999 9.612882 19.000000
      vertex -16.110001 9.612882 19.000000
      vertex 15.636737 9.324287 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 31.407259 -5.308619 19.000000
      vertex 31.130529 -5.787931 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 16.595062 9.877577 19.000000
      vertex -17.094713 10.117715 19.000000
      vertex -16.596062 9.877577 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 16.595062 9.877577 19.000000
      vertex -16.596062 9.877577 19.000000
      vertex 16.108999 9.612882 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 31.659754 -4.816110 19.000000
      vertex 31.407259 -5.308619 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 17.093714 10.117715 19.000000
      vertex -17.094713 10.117715 19.000000
      vertex 16.595062 9.877577 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 31.887386 -4.311626 19.000000
      vertex 31.659754 -4.816110 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 17.603714 10.332699 19.000000
      vertex -18.124798 10.521994 19.000000
      vertex -17.604715 10.332699 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 17.603714 10.332699 19.000000
      vertex -17.604715 10.332699 19.000000
      vertex -17.094713 10.117715 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 17.603714 10.332699 19.000000
      vertex -17.094713 10.117715 19.000000
      vertex 17.093714 10.117715 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 32.089588 -3.796424 19.000000
      vertex 31.887386 -4.311626 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 18.123798 10.521994 19.000000
      vertex -18.124798 10.521994 19.000000
      vertex 17.603714 10.332699 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 32.265858 -3.271782 19.000000
      vertex 32.089588 -3.796424 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 32.415756 -2.739007 19.000000
      vertex 32.265858 -3.271782 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 32.538914 -2.199422 19.000000
      vertex 32.415756 -2.739007 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 32.635021 -1.654369 19.000000
      vertex 32.538914 -2.199422 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 32.703842 -1.105203 19.000000
      vertex 32.635021 -1.654369 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 32.745201 -0.553289 19.000000
      vertex 32.703842 -1.105203 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 32.758999 0.000000 19.000000
      vertex 32.745201 -0.553289 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 19.189018 10.821700 19.000000
      vertex 19.731504 10.931366 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 19.731504 10.931366 19.000000
      vertex 20.278786 11.013855 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 20.278786 11.013855 19.000000
      vertex 20.829496 11.068962 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 20.829496 11.068962 19.000000
      vertex 21.382269 11.096550 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 21.382269 11.096550 19.000000
      vertex 21.935730 11.096550 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 21.935730 11.096550 19.000000
      vertex 22.488504 11.068962 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 22.488504 11.068962 19.000000
      vertex 23.039215 11.013855 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 23.039215 11.013855 19.000000
      vertex 23.586494 10.931366 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 23.586494 10.931366 19.000000
      vertex 24.128983 10.821700 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 24.128983 10.821700 19.000000
      vertex 24.665329 10.685129 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 24.665329 10.685129 19.000000
      vertex 25.194202 10.521994 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 25.194202 10.521994 19.000000
      vertex 25.714285 10.332699 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 25.714285 10.332699 19.000000
      vertex 26.224287 10.117715 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 26.224287 10.117715 19.000000
      vertex 26.722939 9.877577 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 26.722939 9.877577 19.000000
      vertex 27.209000 9.612882 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 27.209000 9.612882 19.000000
      vertex 27.681263 9.324287 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 27.681263 9.324287 19.000000
      vertex 28.138556 9.012512 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 28.138556 9.012512 19.000000
      vertex 28.579737 8.678329 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 28.579737 8.678329 19.000000
      vertex 29.003714 8.322572 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 29.003714 8.322572 19.000000
      vertex 29.409430 7.946122 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 29.409430 7.946122 19.000000
      vertex 29.795876 7.549917 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 29.795876 7.549917 19.000000
      vertex 30.162094 7.134943 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 30.162094 7.134943 19.000000
      vertex 30.507172 6.702229 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 30.507172 6.702229 19.000000
      vertex 30.830250 6.252852 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 30.830250 6.252852 19.000000
      vertex 31.130529 5.787931 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 31.130529 5.787931 19.000000
      vertex 31.407259 5.308619 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 31.407259 5.308619 19.000000
      vertex 31.659754 4.816110 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 31.659754 4.816110 19.000000
      vertex 31.887386 4.311626 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 31.887386 4.311626 19.000000
      vertex 32.089588 3.796424 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 32.089588 3.796424 19.000000
      vertex 32.265858 3.271782 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 32.265858 3.271782 19.000000
      vertex 32.415756 2.739007 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 32.415756 2.739007 19.000000
      vertex 32.538914 2.199422 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 32.538914 2.199422 19.000000
      vertex 32.635021 1.654369 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 32.635021 1.654369 19.000000
      vertex 32.703842 1.105203 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 32.703842 1.105203 19.000000
      vertex 32.745201 0.553289 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 32.745201 0.553289 19.000000
      vertex 32.758999 0.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex 32.758999 0.000000 19.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 50.000000 30.000000 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex 19.189018 10.821700 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 19.189018 10.821700 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex 18.652670 10.685129 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 18.652670 10.685129 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex 18.123798 10.521994 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 18.123798 10.521994 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -18.653671 10.685129 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex -18.653671 10.685129 19.000000
      vertex -50.000000 30.000000 19.000000
      vertex -19.190018 10.821700 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 1.000000
    outer loop
      vertex 18.123798 10.521994 19.000000
      vertex -18.653671 10.685129 19.000000
      vertex -18.124798 10.521994 19.000000
    endloop
  endfacet
  facet normal 0.000000 -1.000000 0.000000
    outer loop
      vertex -50.000000 -30.000000 0.000000
      vertex 50.000000 -30.000000 0.000000
      vertex 50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 0.000000 -1.000000 0.000000
    outer loop
      vertex -50.000000 -30.000000 0.000000
      vertex 50.000000 -30.000000 19.000000
      vertex -50.000000 -30.000000 19.000000
    endloop
  endfacet
  facet normal 1.000000 0.000000 0.000000
    outer loop
      vertex -48.000000 -28.000000 0.000000
      vertex -48.000000 28.000000 0.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 1.000000 -0.000000 0.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -48.000000 28.000000 0.000000
      vertex -48.000000 28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 1.000000 -0.000000
    outer loop
      vertex 48.000000 -28.000000 0.000000
      vertex -48.000000 -28.000000 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 1.000000 0.000000
    outer loop
      vertex 48.000000 -28.000000 0.000000
      vertex -48.000000 -28.000000 0.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal -1.000000 0.000000 0.000000
    outer loop
      vertex 48.000000 28.000000 0.000000
      vertex 48.000000 -28.000000 0.000000
      vertex 48.000000 28.000000 17.000000
    endloop
  endfacet
  facet normal -1.000000 -0.000000 0.000000
    outer loop
      vertex 48.000000 28.000000 17.000000
      vertex 48.000000 -28.000000 0.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 -1.000000 0.000000
    outer loop
      vertex -48.000000 28.000000 0.000000
      vertex 48.000000 28.000000 17.000000
      vertex -48.000000 28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 -1.000000 0.000000
    outer loop
      vertex -48.000000 28.000000 0.000000
      vertex 48.000000 28.000000 0.000000
      vertex 48.000000 28.000000 17.000000
    endloop
  endfacet
  facet normal -0.999689 -0.024930 0.000000
    outer loop
      vertex -10.573798 0.553289 17.000000
      vertex -10.560000 0.000000 17.000000
      vertex -10.560000 0.000000 19.000000
    endloop
  endfacet
  facet normal -0.999689 -0.024930 0.000000
    outer loop
      vertex -10.573798 0.553289 17.000000
      vertex -10.560000 0.000000 19.000000
      vertex -10.573798 0.553289 19.000000
    endloop
  endfacet
  facet normal -0.997204 -0.074730 0.000000
    outer loop
      vertex -10.615158 1.105203 17.000000
      vertex -10.573798 0.553289 19.000000
      vertex -10.615158 1.105203 19.000000
    endloop
  endfacet
  facet normal -0.997204 -0.074730 0.000000
    outer loop
      vertex -10.615158 1.105203 17.000000
      vertex -10.573798 0.553289 17.000000
      vertex -10.573798 0.553289 19.000000
    endloop
  endfacet
  facet normal -0.992239 -0.124345 0.000000
    outer loop
      vertex -10.683978 1.654369 17.000000
      vertex -10.615158 1.105203 19.000000
      vertex -10.683978 1.654369 19.000000
    endloop
  endfacet
  facet normal -0.992239 -0.124345 0.000000
    outer loop
      vertex -10.683978 1.654369 17.000000
      vertex -10.615158 1.105203 17.000000
      vertex -10.615158 1.105203 19.000000
    endloop
  endfacet
  facet normal -0.984808 -0.173648 0.000000
    outer loop
      vertex -10.780086 2.199422 17.000000
      vertex -10.683978 1.654369 19.000000
      vertex -10.780086 2.199422 19.000000
    endloop
  endfacet
  facet normal -0.984808 -0.173648 0.000000
    outer loop
      vertex -10.780086 2.199422 17.000000
      vertex -10.683978 1.654369 17.000000
      vertex -10.683978 1.654369 19.000000
    endloop
  endfacet
  facet normal -0.974928 -0.222521 0.000000
    outer loop
      vertex -10.903242 2.739007 17.000000
      vertex -10.780086 2.199422 19.000000
      vertex -10.903242 2.739007 19.000000
    endloop
  endfacet
  facet normal -0.974928 -0.222521 0.000000
    outer loop
      vertex -10.903242 2.739007 17.000000
      vertex -10.780086 2.199422 17.000000
      vertex -10.780086 2.199422 19.000000
    endloop
  endfacet
  facet normal -0.962624 -0.270840 0.000000
    outer loop
      vertex -11.053142 3.271782 17.000000
      vertex -10.903242 2.739007 19.000000
      vertex -11.053142 3.271782 19.000000
    endloop
  endfacet
  facet normal -0.962624 -0.270840 0.000000
    outer loop
      vertex -11.053142 3.271782 17.000000
      vertex -10.903242 2.739007 17.000000
      vertex -10.903242 2.739007 19.000000
    endloop
  endfacet
  facet normal -0.947927 -0.318487 0.000000
    outer loop
      vertex -11.229412 3.796424 17.000000
      vertex -11.053142 3.271782 19.000000
      vertex -11.229412 3.796424 19.000000
    endloop
  endfacet
  facet normal -0.947927 -0.318487 0.000000
    outer loop
      vertex -11.229412 3.796424 17.000000
      vertex -11.053142 3.271782 17.000000
      vertex -11.053142 3.271782 19.000000
    endloop
  endfacet
  facet normal -0.930874 -0.365340 0.000000
    outer loop
      vertex -11.431614 4.311626 17.000000
      vertex -11.229412 3.796424 19.000000
      vertex -11.431614 4.311626 19.000000
    endloop
  endfacet
  facet normal -0.930874 -0.365340 0.000000
    outer loop
      vertex -11.431614 4.311626 17.000000
      vertex -11.229412 3.796424 17.000000
      vertex -11.229412 3.796424 19.000000
    endloop
  endfacet
  facet normal -0.911506 -0.411287 0.000000
    outer loop
      vertex -11.659245 4.816110 17.000000
      vertex -11.431614 4.311626 19.000000
      vertex -11.659245 4.816110 19.000000
    endloop
  endfacet
  facet normal -0.911506 -0.411287 0.000000
    outer loop
      vertex -11.659245 4.816110 17.000000
      vertex -11.431614 4.311626 17.000000
      vertex -11.431614 4.311626 19.000000
    endloop
  endfacet
  facet normal -0.889872 -0.456211 0.000000
    outer loop
      vertex -11.911740 5.308619 17.000000
      vertex -11.659245 4.816110 19.000000
      vertex -11.911740 5.308619 19.000000
    endloop
  endfacet
  facet normal -0.889872 -0.456211 0.000000
    outer loop
      vertex -11.911740 5.308619 17.000000
      vertex -11.659245 4.816110 17.000000
      vertex -11.659245 4.816110 19.000000
    endloop
  endfacet
  facet normal -0.866026 -0.500000 0.000000
    outer loop
      vertex -12.188471 5.787931 17.000000
      vertex -11.911740 5.308619 17.000000
      vertex -11.911740 5.308619 19.000000
    endloop
  endfacet
  facet normal -0.866026 -0.500000 0.000000
    outer loop
      vertex -12.188471 5.787931 17.000000
      vertex -11.911740 5.308619 19.000000
      vertex -12.188471 5.787931 19.000000
    endloop
  endfacet
  facet normal -0.840025 -0.542547 0.000000
    outer loop
      vertex -12.488750 6.252852 17.000000
      vertex -12.188471 5.787931 17.000000
      vertex -12.188471 5.787931 19.000000
    endloop
  endfacet
  facet normal -0.840025 -0.542547 0.000000
    outer loop
      vertex -12.488750 6.252852 17.000000
      vertex -12.188471 5.787931 19.000000
      vertex -12.488750 6.252852 19.000000
    endloop
  endfacet
  facet normal -0.811938 -0.583744 0.000000
    outer loop
      vertex -12.811830 6.702229 17.000000
      vertex -12.488750 6.252852 17.000000
      vertex -12.488750 6.252852 19.000000
    endloop
  endfacet
  facet normal -0.811938 -0.583744 0.000000
    outer loop
      vertex -12.811830 6.702229 17.000000
      vertex -12.488750 6.252852 19.000000
      vertex -12.811830 6.702229 19.000000
    endloop
  endfacet
  facet normal -0.781831 -0.623490 0.000000
    outer loop
      vertex -13.156907 7.134943 17.000000
      vertex -12.811830 6.702229 17.000000
      vertex -12.811830 6.702229 19.000000
    endloop
  endfacet
  facet normal -0.781831 -0.623490 0.000000
    outer loop
      vertex -13.156907 7.134943 17.000000
      vertex -12.811830 6.702229 19.000000
      vertex -13.156907 7.134943 19.000000
    endloop
  endfacet
  facet normal -0.749781 -0.661686 0.000000
    outer loop
      vertex -13.523125 7.549917 17.000000
      vertex -13.156907 7.134943 17.000000
      vertex -13.156907 7.134943 19.000000
    endloop
  endfacet
  facet normal -0.749781 -0.661686 0.000000
    outer loop
      vertex -13.523125 7.549917 17.000000
      vertex -13.156907 7.134943 19.000000
      vertex -13.523125 7.549917 19.000000
    endloop
  endfacet
  facet normal -0.715867 -0.698236 0.000000
    outer loop
      vertex -13.909572 7.946122 17.000000
      vertex -13.523125 7.549917 17.000000
      vertex -13.523125 7.549917 19.000000
    endloop
  endfacet
  facet normal -0.715867 -0.698236 0.000000
    outer loop
      vertex -13.909572 7.946122 17.000000
      vertex -13.523125 7.549917 19.000000
      vertex -13.909572 7.946122 19.000000
    endloop
  endfacet
  facet normal -0.680173 -0.733052 0.000000
    outer loop
      vertex -14.315288 8.322572 17.000000
      vertex -13.909572 7.946122 17.000000
      vertex -13.909572 7.946122 19.000000
    endloop
  endfacet
  facet normal -0.680173 -0.733052 0.000000
    outer loop
      vertex -14.315288 8.322572 17.000000
      vertex -13.909572 7.946122 19.000000
      vertex -14.315288 8.322572 19.000000
    endloop
  endfacet
  facet normal -0.642787 -0.766045 0.000000
    outer loop
      vertex -14.739264 8.678329 17.000000
      vertex -14.315288 8.322572 17.000000
      vertex -14.315288 8.322572 19.000000
    endloop
  endfacet
  facet normal -0.642787 -0.766045 0.000000
    outer loop
      vertex -14.739264 8.678329 17.000000
      vertex -14.315288 8.322572 19.000000
      vertex -14.739264 8.678329 19.000000
    endloop
  endfacet
  facet normal -0.603805 -0.797132 0.000000
    outer loop
      vertex -15.180446 9.012512 17.000000
      vertex -14.739264 8.678329 19.000000
      vertex -15.180446 9.012512 19.000000
    endloop
  endfacet
  facet normal -0.603805 -0.797132 0.000000
    outer loop
      vertex -15.180446 9.012512 17.000000
      vertex -14.739264 8.678329 17.000000
      vertex -14.739264 8.678329 19.000000
    endloop
  endfacet
  facet normal -0.563320 -0.826239 0.000000
    outer loop
      vertex -15.637736 9.324287 17.000000
      vertex -15.180446 9.012512 19.000000
      vertex -15.637736 9.324287 19.000000
    endloop
  endfacet
  facet normal -0.563320 -0.826239 0.000000
    outer loop
      vertex -15.637736 9.324287 17.000000
      vertex -15.180446 9.012512 17.000000
      vertex -15.180446 9.012512 19.000000
    endloop
  endfacet
  facet normal -0.521435 -0.853291 0.000000
    outer loop
      vertex -16.110001 9.612882 17.000000
      vertex -15.637736 9.324287 19.000000
      vertex -16.110001 9.612882 19.000000
    endloop
  endfacet
  facet normal -0.521435 -0.853291 0.000000
    outer loop
      vertex -16.110001 9.612882 17.000000
      vertex -15.637736 9.324287 17.000000
      vertex -15.637736 9.324287 19.000000
    endloop
  endfacet
  facet normal -0.478254 -0.878221 0.000000
    outer loop
      vertex -16.596062 9.877577 17.000000
      vertex -16.110001 9.612882 19.000000
      vertex -16.596062 9.877577 19.000000
    endloop
  endfacet
  facet normal -0.478254 -0.878221 0.000000
    outer loop
      vertex -16.596062 9.877577 17.000000
      vertex -16.110001 9.612882 17.000000
      vertex -16.110001 9.612882 19.000000
    endloop
  endfacet
  facet normal -0.433884 -0.900969 0.000000
    outer loop
      vertex -17.094713 10.117715 17.000000
      vertex -16.596062 9.877577 19.000000
      vertex -17.094713 10.117715 19.000000
    endloop
  endfacet
  facet normal -0.433884 -0.900969 0.000000
    outer loop
      vertex -17.094713 10.117715 17.000000
      vertex -16.596062 9.877577 17.000000
      vertex -16.596062 9.877577 19.000000
    endloop
  endfacet
  facet normal -0.388435 -0.921476 0.000000
    outer loop
      vertex -17.604715 10.332699 17.000000
      vertex -17.094713 10.117715 19.000000
      vertex -17.604715 10.332699 19.000000
    endloop
  endfacet
  facet normal -0.388435 -0.921476 0.000000
    outer loop
      vertex -17.604715 10.332699 17.000000
      vertex -17.094713 10.117715 17.000000
      vertex -17.094713 10.117715 19.000000
    endloop
  endfacet
  facet normal -0.294755 -0.955573 0.000000
    outer loop
      vertex -18.124798 10.521994 17.000000
      vertex -18.124798 10.521994 19.000000
      vertex -18.653671 10.685129 19.000000
    endloop
  endfacet
  facet normal -0.342021 -0.939692 0.000000
    outer loop
      vertex -18.124798 10.521994 17.000000
      vertex -17.604715 10.332699 19.000000
      vertex -18.124798 10.521994 19.000000
    endloop
  endfacet
  facet normal -0.342021 -0.939692 0.000000
    outer loop
      vertex -18.124798 10.521994 17.000000
      vertex -17.604715 10.332699 17.000000
      vertex -17.604715 10.332699 19.000000
    endloop
  endfacet
  facet normal -0.294755 -0.955573 0.000000
    outer loop
      vertex -18.653671 10.685129 17.000000
      vertex -18.124798 10.521994 17.000000
      vertex -18.653671 10.685129 19.000000
    endloop
  endfacet
  facet normal -0.198145 -0.980173 0.000000
    outer loop
      vertex -19.190018 10.821700 17.000000
      vertex -19.190018 10.821700 19.000000
      vertex -19.732506 10.931366 19.000000
    endloop
  endfacet
  facet normal -0.246758 -0.969077 0.000000
    outer loop
      vertex -19.190018 10.821700 17.000000
      vertex -18.653671 10.685129 19.000000
      vertex -19.190018 10.821700 19.000000
    endloop
  endfacet
  facet normal -0.246758 -0.969077 0.000000
    outer loop
      vertex -19.190018 10.821700 17.000000
      vertex -18.653671 10.685129 17.000000
      vertex -18.653671 10.685129 19.000000
    endloop
  endfacet
  facet normal -0.198145 -0.980173 0.000000
    outer loop
      vertex -19.732506 10.931366 17.000000
      vertex -19.190018 10.821700 17.000000
      vertex -19.732506 10.931366 19.000000
    endloop
  endfacet
  facet normal -0.149042 -0.988831 0.000000
    outer loop
      vertex -20.279785 11.013855 17.000000
      vertex -19.732506 10.931366 19.000000
      vertex -20.279785 11.013855 19.000000
    endloop
  endfacet
  facet normal -0.149042 -0.988831 0.000000
    outer loop
      vertex -20.279785 11.013855 17.000000
      vertex -19.732506 10.931366 17.000000
      vertex -19.732506 10.931366 19.000000
    endloop
  endfacet
  facet normal -0.099568 -0.995031 0.000000
    outer loop
      vertex -20.830496 11.068962 17.000000
      vertex -20.279785 11.013855 19.000000
      vertex -20.830496 11.068962 19.000000
    endloop
  endfacet
  facet normal -0.099568 -0.995031 0.000000
    outer loop
      vertex -20.830496 11.068962 17.000000
      vertex -20.279785 11.013855 17.000000
      vertex -20.279785 11.013855 19.000000
    endloop
  endfacet
  facet normal -0.049846 -0.998757 0.000000
    outer loop
      vertex -21.383270 11.096550 17.000000
      vertex -20.830496 11.068962 19.000000
      vertex -21.383270 11.096550 19.000000
    endloop
  endfacet
  facet normal -0.049846 -0.998757 0.000000
    outer loop
      vertex -21.383270 11.096550 17.000000
      vertex -20.830496 11.068962 17.000000
      vertex -20.830496 11.068962 19.000000
    endloop
  endfacet
  facet normal 0.000000 -1.000000 0.000000
    outer loop
      vertex -21.936731 11.096550 17.000000
      vertex -21.383270 11.096550 19.000000
      vertex -21.936731 11.096550 19.000000
    endloop
  endfacet
  facet normal 0.000000 -1.000000 0.000000
    outer loop
      vertex -21.936731 11.096550 17.000000
      vertex -21.383270 11.096550 17.000000
      vertex -21.383270 11.096550 19.000000
    endloop
  endfacet
  facet normal 0.099568 -0.995031 0.000000
    outer loop
      vertex -22.489504 11.068962 17.000000
      vertex -22.489504 11.068962 19.000000
      vertex -23.040215 11.013855 19.000000
    endloop
  endfacet
  facet normal 0.049846 -0.998757 0.000000
    outer loop
      vertex -22.489504 11.068962 17.000000
      vertex -21.936731 11.096550 19.000000
      vertex -22.489504 11.068962 19.000000
    endloop
  endfacet
  facet normal 0.049846 -0.998757 0.000000
    outer loop
      vertex -22.489504 11.068962 17.000000
      vertex -21.936731 11.096550 17.000000
      vertex -21.936731 11.096550 19.000000
    endloop
  endfacet
  facet normal 0.099568 -0.995031 0.000000
    outer loop
      vertex -23.040215 11.013855 17.000000
      vertex -22.489504 11.068962 17.000000
      vertex -23.040215 11.013855 19.000000
    endloop
  endfacet
  facet normal 0.198145 -0.980173 0.000000
    outer loop
      vertex -23.587494 10.931366 17.000000
      vertex -23.587494 10.931366 19.000000
      vertex -24.129982 10.821700 19.000000
    endloop
  endfacet
  facet normal 0.149042 -0.988831 0.000000
    outer loop
      vertex -23.587494 10.931366 17.000000
      vertex -23.040215 11.013855 19.000000
      vertex -23.587494 10.931366 19.000000
    endloop
  endfacet
  facet normal 0.149042 -0.988831 0.000000
    outer loop
      vertex -23.587494 10.931366 17.000000
      vertex -23.040215 11.013855 17.000000
      vertex -23.040215 11.013855 19.000000
    endloop
  endfacet
  facet normal 0.198145 -0.980173 0.000000
    outer loop
      vertex -24.129982 10.821700 17.000000
      vertex -23.587494 10.931366 17.000000
      vertex -24.129982 10.821700 19.000000
    endloop
  endfacet
  facet normal 0.246758 -0.969077 0.000000
    outer loop
      vertex -24.666328 10.685129 17.000000
      vertex -24.129982 10.821700 17.000000
      vertex -24.129982 10.821700 19.000000
    endloop
  endfacet
  facet normal 0.294755 -0.955573 0.000000
    outer loop
      vertex -24.666328 10.685129 17.000000
      vertex -24.666328 10.685129 19.000000
      vertex -25.195202 10.521994 19.000000
    endloop
  endfacet
  facet normal 0.246758 -0.969077 0.000000
    outer loop
      vertex -24.666328 10.685129 17.000000
      vertex -24.129982 10.821700 19.000000
      vertex -24.666328 10.685129 19.000000
    endloop
  endfacet
  facet normal 0.294755 -0.955573 0.000000
    outer loop
      vertex -25.195202 10.521994 17.000000
      vertex -24.666328 10.685129 17.000000
      vertex -25.195202 10.521994 19.000000
    endloop
  endfacet
  facet normal 0.388436 -0.921476 0.000000
    outer loop
      vertex -25.715286 10.332699 17.000000
      vertex -25.715286 10.332699 19.000000
      vertex -26.225286 10.117715 19.000000
    endloop
  endfacet
  facet normal 0.342019 -0.939693 0.000000
    outer loop
      vertex -25.715286 10.332699 17.000000
      vertex -25.195202 10.521994 19.000000
      vertex -25.715286 10.332699 19.000000
    endloop
  endfacet
  facet normal 0.342019 -0.939693 0.000000
    outer loop
      vertex -25.715286 10.332699 17.000000
      vertex -25.195202 10.521994 17.000000
      vertex -25.195202 10.521994 19.000000
    endloop
  endfacet
  facet normal 0.388436 -0.921476 0.000000
    outer loop
      vertex -26.225286 10.117715 17.000000
      vertex -25.715286 10.332699 17.000000
      vertex -26.225286 10.117715 19.000000
    endloop
  endfacet
  facet normal 0.478254 -0.878221 0.000000
    outer loop
      vertex -26.723938 9.877577 17.000000
      vertex -26.723938 9.877577 19.000000
      vertex -27.209999 9.612882 19.000000
    endloop
  endfacet
  facet normal 0.433884 -0.900969 0.000000
    outer loop
      vertex -26.723938 9.877577 17.000000
      vertex -26.225286 10.117715 19.000000
      vertex -26.723938 9.877577 19.000000
    endloop
  endfacet
  facet normal 0.433884 -0.900969 0.000000
    outer loop
      vertex -26.723938 9.877577 17.000000
      vertex -26.225286 10.117715 17.000000
      vertex -26.225286 10.117715 19.000000
    endloop
  endfacet
  facet normal 0.478254 -0.878221 0.000000
    outer loop
      vertex -27.209999 9.612882 17.000000
      vertex -26.723938 9.877577 17.000000
      vertex -27.209999 9.612882 19.000000
    endloop
  endfacet
  facet normal 0.563320 -0.826239 0.000000
    outer loop
      vertex -27.682264 9.324287 17.000000
      vertex -27.682264 9.324287 19.000000
      vertex -28.139555 9.012512 19.000000
    endloop
  endfacet
  facet normal 0.521434 -0.853292 0.000000
    outer loop
      vertex -27.682264 9.324287 17.000000
      vertex -27.209999 9.612882 19.000000
      vertex -27.682264 9.324287 19.000000
    endloop
  endfacet
  facet normal 0.521434 -0.853292 0.000000
    outer loop
      vertex -27.682264 9.324287 17.000000
      vertex -27.209999 9.612882 17.000000
      vertex -27.209999 9.612882 19.000000
    endloop
  endfacet
  facet normal 0.603805 -0.797132 0.000000
    outer loop
      vertex -28.139555 9.012512 17.000000
      vertex -28.139555 9.012512 19.000000
      vertex -28.580736 8.678329 19.000000
    endloop
  endfacet
  facet normal 0.563320 -0.826239 0.000000
    outer loop
      vertex -28.139555 9.012512 17.000000
      vertex -27.682264 9.324287 17.000000
      vertex -28.139555 9.012512 19.000000
    endloop
  endfacet
  facet normal 0.603805 -0.797132 0.000000
    outer loop
      vertex -28.580736 8.678329 17.000000
      vertex -28.139555 9.012512 17.000000
      vertex -28.580736 8.678329 19.000000
    endloop
  endfacet
  facet normal 0.680173 -0.733052 0.000000
    outer loop
      vertex -29.004713 8.322572 17.000000
      vertex -29.004713 8.322572 19.000000
      vertex -29.410429 7.946122 19.000000
    endloop
  endfacet
  facet normal 0.642786 -0.766045 0.000000
    outer loop
      vertex -29.004713 8.322572 17.000000
      vertex -28.580736 8.678329 19.000000
      vertex -29.004713 8.322572 19.000000
    endloop
  endfacet
  facet normal 0.642786 -0.766045 0.000000
    outer loop
      vertex -29.004713 8.322572 17.000000
      vertex -28.580736 8.678329 17.000000
      vertex -28.580736 8.678329 19.000000
    endloop
  endfacet
  facet normal 0.680173 -0.733052 0.000000
    outer loop
      vertex -29.410429 7.946122 17.000000
      vertex -29.004713 8.322572 17.000000
      vertex -29.410429 7.946122 19.000000
    endloop
  endfacet
  facet normal 0.749780 -0.661687 0.000000
    outer loop
      vertex -29.796875 7.549917 17.000000
      vertex -29.796875 7.549917 19.000000
      vertex -30.163094 7.134943 19.000000
    endloop
  endfacet
  facet normal 0.715868 -0.698236 0.000000
    outer loop
      vertex -29.796875 7.549917 17.000000
      vertex -29.410429 7.946122 19.000000
      vertex -29.796875 7.549917 19.000000
    endloop
  endfacet
  facet normal 0.715868 -0.698236 0.000000
    outer loop
      vertex -29.796875 7.549917 17.000000
      vertex -29.410429 7.946122 17.000000
      vertex -29.410429 7.946122 19.000000
    endloop
  endfacet
  facet normal 0.781831 -0.623490 0.000000
    outer loop
      vertex -30.163094 7.134943 17.000000
      vertex -30.163094 7.134943 19.000000
      vertex -30.508171 6.702229 19.000000
    endloop
  endfacet
  facet normal 0.749780 -0.661687 0.000000
    outer loop
      vertex -30.163094 7.134943 17.000000
      vertex -29.796875 7.549917 17.000000
      vertex -30.163094 7.134943 19.000000
    endloop
  endfacet
  facet normal 0.811938 -0.583744 0.000000
    outer loop
      vertex -30.508171 6.702229 17.000000
      vertex -30.508171 6.702229 19.000000
      vertex -30.831251 6.252852 19.000000
    endloop
  endfacet
  facet normal 0.781831 -0.623490 0.000000
    outer loop
      vertex -30.508171 6.702229 17.000000
      vertex -30.163094 7.134943 17.000000
      vertex -30.508171 6.702229 19.000000
    endloop
  endfacet
  facet normal 0.811938 -0.583744 0.000000
    outer loop
      vertex -30.831251 6.252852 17.000000
      vertex -30.508171 6.702229 17.000000
      vertex -30.831251 6.252852 19.000000
    endloop
  endfacet
  facet normal 0.840026 -0.542546 0.000000
    outer loop
      vertex -31.131529 5.787931 17.000000
      vertex -30.831251 6.252852 19.000000
      vertex -31.131529 5.787931 19.000000
    endloop
  endfacet
  facet normal 0.840026 -0.542546 0.000000
    outer loop
      vertex -31.131529 5.787931 17.000000
      vertex -30.831251 6.252852 17.000000
      vertex -30.831251 6.252852 19.000000
    endloop
  endfacet
  facet normal 0.866025 -0.500001 0.000000
    outer loop
      vertex -31.408260 5.308619 17.000000
      vertex -31.131529 5.787931 17.000000
      vertex -31.131529 5.787931 19.000000
    endloop
  endfacet
  facet normal 0.866025 -0.500001 0.000000
    outer loop
      vertex -31.408260 5.308619 17.000000
      vertex -31.131529 5.787931 19.000000
      vertex -31.408260 5.308619 19.000000
    endloop
  endfacet
  facet normal 0.889872 -0.456211 0.000000
    outer loop
      vertex -31.660755 4.816110 17.000000
      vertex -31.408260 5.308619 17.000000
      vertex -31.408260 5.308619 19.000000
    endloop
  endfacet
  facet normal 0.911506 -0.411286 0.000000
    outer loop
      vertex -31.660755 4.816110 17.000000
      vertex -31.660755 4.816110 19.000000
      vertex -31.888386 4.311626 19.000000
    endloop
  endfacet
  facet normal 0.889872 -0.456211 0.000000
    outer loop
      vertex -31.660755 4.816110 17.000000
      vertex -31.408260 5.308619 19.000000
      vertex -31.660755 4.816110 19.000000
    endloop
  endfacet
  facet normal 0.911506 -0.411286 0.000000
    outer loop
      vertex -31.888386 4.311626 17.000000
      vertex -31.660755 4.816110 17.000000
      vertex -31.888386 4.311626 19.000000
    endloop
  endfacet
  facet normal 0.930874 -0.365340 0.000000
    outer loop
      vertex -32.090588 3.796424 17.000000
      vertex -31.888386 4.311626 17.000000
      vertex -31.888386 4.311626 19.000000
    endloop
  endfacet
  facet normal 0.947928 -0.318486 0.000000
    outer loop
      vertex -32.090588 3.796424 17.000000
      vertex -32.090588 3.796424 19.000000
      vertex -32.266857 3.271782 19.000000
    endloop
  endfacet
  facet normal 0.930874 -0.365340 0.000000
    outer loop
      vertex -32.090588 3.796424 17.000000
      vertex -31.888386 4.311626 19.000000
      vertex -32.090588 3.796424 19.000000
    endloop
  endfacet
  facet normal 0.947928 -0.318486 0.000000
    outer loop
      vertex -32.266857 3.271782 17.000000
      vertex -32.090588 3.796424 17.000000
      vertex -32.266857 3.271782 19.000000
    endloop
  endfacet
  facet normal 0.962623 -0.270845 0.000000
    outer loop
      vertex -32.416759 2.739007 17.000000
      vertex -32.266857 3.271782 17.000000
      vertex -32.266857 3.271782 19.000000
    endloop
  endfacet
  facet normal 0.974929 -0.222516 0.000000
    outer loop
      vertex -32.416759 2.739007 17.000000
      vertex -32.416759 2.739007 19.000000
      vertex -32.539913 2.199422 19.000000
    endloop
  endfacet
  facet normal 0.962623 -0.270845 0.000000
    outer loop
      vertex -32.416759 2.739007 17.000000
      vertex -32.266857 3.271782 19.000000
      vertex -32.416759 2.739007 19.000000
    endloop
  endfacet
  facet normal 0.984808 -0.173648 0.000000
    outer loop
      vertex -32.539913 2.199422 17.000000
      vertex -32.539913 2.199422 19.000000
      vertex -32.636021 1.654369 19.000000
    endloop
  endfacet
  facet normal 0.974929 -0.222516 0.000000
    outer loop
      vertex -32.539913 2.199422 17.000000
      vertex -32.416759 2.739007 17.000000
      vertex -32.539913 2.199422 19.000000
    endloop
  endfacet
  facet normal 0.984808 -0.173648 0.000000
    outer loop
      vertex -32.636021 1.654369 17.000000
      vertex -32.539913 2.199422 17.000000
      vertex -32.636021 1.654369 19.000000
    endloop
  endfacet
  facet normal 0.997204 -0.074728 0.000000
    outer loop
      vertex -32.704842 1.105203 17.000000
      vertex -32.704842 1.105203 19.000000
      vertex -32.746201 0.553289 19.000000
    endloop
  endfacet
  facet normal 0.992239 -0.124346 0.000000
    outer loop
      vertex -32.704842 1.105203 17.000000
      vertex -32.636021 1.654369 19.000000
      vertex -32.704842 1.105203 19.000000
    endloop
  endfacet
  facet normal 0.992239 -0.124346 0.000000
    outer loop
      vertex -32.704842 1.105203 17.000000
      vertex -32.636021 1.654369 17.000000
      vertex -32.636021 1.654369 19.000000
    endloop
  endfacet
  facet normal 0.997204 -0.074728 0.000000
    outer loop
      vertex -32.746201 0.553289 17.000000
      vertex -32.704842 1.105203 17.000000
      vertex -32.746201 0.553289 19.000000
    endloop
  endfacet
  facet normal 0.999689 -0.024930 0.000000
    outer loop
      vertex -32.759998 0.000000 17.000000
      vertex -32.746201 0.553289 17.000000
      vertex -32.746201 0.553289 19.000000
    endloop
  endfacet
  facet normal 0.999689 0.024930 -0.000000
    outer loop
      vertex -32.759998 0.000000 17.000000
      vertex -32.759998 0.000000 19.000000
      vertex -32.746201 -0.553289 19.000000
    endloop
  endfacet
  facet normal 0.999689 -0.024930 0.000000
    outer loop
      vertex -32.759998 0.000000 17.000000
      vertex -32.746201 0.553289 19.000000
      vertex -32.759998 0.000000 19.000000
    endloop
  endfacet
  facet normal 0.999689 0.024930 -0.000000
    outer loop
      vertex -32.746201 -0.553289 17.000000
      vertex -32.759998 0.000000 17.000000
      vertex -32.746201 -0.553289 19.000000
    endloop
  endfacet
  facet normal 0.997204 0.074728 0.000000
    outer loop
      vertex -32.704842 -1.105203 17.000000
      vertex -32.746201 -0.553289 17.000000
      vertex -32.746201 -0.553289 19.000000
    endloop
  endfacet
  facet normal 0.997204 0.074728 -0.000000
    outer loop
      vertex -32.704842 -1.105203 17.000000
      vertex -32.746201 -0.553289 19.000000
      vertex -32.704842 -1.105203 19.000000
    endloop
  endfacet
  facet normal 0.992239 0.124346 0.000000
    outer loop
      vertex -32.636021 -1.654369 17.000000
      vertex -32.704842 -1.105203 17.000000
      vertex -32.704842 -1.105203 19.000000
    endloop
  endfacet
  facet normal 0.992239 0.124346 -0.000000
    outer loop
      vertex -32.636021 -1.654369 17.000000
      vertex -32.704842 -1.105203 19.000000
      vertex -32.636021 -1.654369 19.000000
    endloop
  endfacet
  facet normal 0.984808 0.173648 0.000000
    outer loop
      vertex -32.539913 -2.199422 17.000000
      vertex -32.636021 -1.654369 17.000000
      vertex -32.636021 -1.654369 19.000000
    endloop
  endfacet
  facet normal 0.974929 0.222516 -0.000000
    outer loop
      vertex -32.539913 -2.199422 17.000000
      vertex -32.539913 -2.199422 19.000000
      vertex -32.416759 -2.739007 19.000000
    endloop
  endfacet
  facet normal 0.984808 0.173648 -0.000000
    outer loop
      vertex -32.539913 -2.199422 17.000000
      vertex -32.636021 -1.654369 19.000000
      vertex -32.539913 -2.199422 19.000000
    endloop
  endfacet
  facet normal 0.974929 0.222516 -0.000000
    outer loop
      vertex -32.416759 -2.739007 17.000000
      vertex -32.539913 -2.199422 17.000000
      vertex -32.416759 -2.739007 19.000000
    endloop
  endfacet
  facet normal 0.962623 0.270845 0.000000
    outer loop
      vertex -32.266857 -3.271782 17.000000
      vertex -32.416759 -2.739007 17.000000
      vertex -32.416759 -2.739007 19.000000
    endloop
  endfacet
  facet normal 0.962623 0.270845 -0.000000
    outer loop
      vertex -32.266857 -3.271782 17.000000
      vertex -32.416759 -2.739007 19.000000
      vertex -32.266857 -3.271782 19.000000
    endloop
  endfacet
  facet normal 0.947928 0.318486 0.000000
    outer loop
      vertex -32.090588 -3.796424 17.000000
      vertex -32.266857 -3.271782 17.000000
      vertex -32.266857 -3.271782 19.000000
    endloop
  endfacet
  facet normal 0.947928 0.318486 -0.000000
    outer loop
      vertex -32.090588 -3.796424 17.000000
      vertex -32.266857 -3.271782 19.000000
      vertex -32.090588 -3.796424 19.000000
    endloop
  endfacet
  facet normal 0.930874 0.365340 0.000000
    outer loop
      vertex -31.888386 -4.311626 17.000000
      vertex -32.090588 -3.796424 17.000000
      vertex -32.090588 -3.796424 19.000000
    endloop
  endfacet
  facet normal 0.930874 0.365340 -0.000000
    outer loop
      vertex -31.888386 -4.311626 17.000000
      vertex -32.090588 -3.796424 19.000000
      vertex -31.888386 -4.311626 19.000000
    endloop
  endfacet
  facet normal 0.911506 0.411286 0.000000
    outer loop
      vertex -31.660755 -4.816110 17.000000
      vertex -31.888386 -4.311626 17.000000
      vertex -31.888386 -4.311626 19.000000
    endloop
  endfacet
  facet normal 0.911506 0.411286 -0.000000
    outer loop
      vertex -31.660755 -4.816110 17.000000
      vertex -31.888386 -4.311626 19.000000
      vertex -31.660755 -4.816110 19.000000
    endloop
  endfacet
  facet normal 0.889872 0.456211 0.000000
    outer loop
      vertex -31.408260 -5.308619 17.000000
      vertex -31.660755 -4.816110 17.000000
      vertex -31.660755 -4.816110 19.000000
    endloop
  endfacet
  facet normal 0.889872 0.456211 -0.000000
    outer loop
      vertex -31.408260 -5.308619 17.000000
      vertex -31.660755 -4.816110 19.000000
      vertex -31.408260 -5.308619 19.000000
    endloop
  endfacet
  facet normal 0.866025 0.500001 0.000000
    outer loop
      vertex -31.131529 -5.787931 17.000000
      vertex -31.408260 -5.308619 17.000000
      vertex -31.408260 -5.308619 19.000000
    endloop
  endfacet
  facet normal 0.866025 0.500001 -0.000000
    outer loop
      vertex -31.131529 -5.787931 17.000000
      vertex -31.408260 -5.308619 19.000000
      vertex -31.131529 -5.787931 19.000000
    endloop
  endfacet
  facet normal 0.840026 0.542546 0.000000
    outer loop
      vertex -30.831251 -6.252852 17.000000
      vertex -31.131529 -5.787931 17.000000
      vertex -31.131529 -5.787931 19.000000
    endloop
  endfacet
  facet normal 0.840026 0.542546 -0.000000
    outer loop
      vertex -30.831251 -6.252852 17.000000
      vertex -31.131529 -5.787931 19.000000
      vertex -30.831251 -6.252852 19.000000
    endloop
  endfacet
  facet normal 0.811938 0.583744 0.000000
    outer loop
      vertex -30.508171 -6.702229 17.000000
      vertex -30.831251 -6.252852 17.000000
      vertex -30.831251 -6.252852 19.000000
    endloop
  endfacet
  facet normal 0.811938 0.583744 -0.000000
    outer loop
      vertex -30.508171 -6.702229 17.000000
      vertex -30.831251 -6.252852 19.000000
      vertex -30.508171 -6.702229 19.000000
    endloop
  endfacet
  facet normal 0.781831 0.623490 0.000000
    outer loop
      vertex -30.163094 -7.134943 17.000000
      vertex -30.508171 -6.702229 17.000000
      vertex -30.508171 -6.702229 19.000000
    endloop
  endfacet
  facet normal 0.781831 0.623490 -0.000000
    outer loop
      vertex -30.163094 -7.134943 17.000000
      vertex -30.508171 -6.702229 19.000000
      vertex -30.163094 -7.134943 19.000000
    endloop
  endfacet
  facet normal 0.749780 0.661687 0.000000
    outer loop
      vertex -29.796875 -7.549917 17.000000
      vertex -30.163094 -7.134943 17.000000
      vertex -30.163094 -7.134943 19.000000
    endloop
  endfacet
  facet normal 0.749780 0.661687 -0.000000
    outer loop
      vertex -29.796875 -7.549917 17.000000
      vertex -30.163094 -7.134943 19.000000
      vertex -29.796875 -7.549917 19.000000
    endloop
  endfacet
  facet normal 0.715868 0.698236 0.000000
    outer loop
      vertex -29.410429 -7.946122 17.000000
      vertex -29.796875 -7.549917 17.000000
      vertex -29.796875 -7.549917 19.000000
    endloop
  endfacet
  facet normal 0.680173 0.733052 -0.000000
    outer loop
      vertex -29.410429 -7.946122 17.000000
      vertex -29.410429 -7.946122 19.000000
      vertex -29.004713 -8.322572 19.000000
    endloop
  endfacet
  facet normal 0.715868 0.698236 -0.000000
    outer loop
      vertex -29.410429 -7.946122 17.000000
      vertex -29.796875 -7.549917 19.000000
      vertex -29.410429 -7.946122 19.000000
    endloop
  endfacet
  facet normal 0.680173 0.733052 -0.000000
    outer loop
      vertex -29.004713 -8.322572 17.000000
      vertex -29.410429 -7.946122 17.000000
      vertex -29.004713 -8.322572 19.000000
    endloop
  endfacet
  facet normal 0.603805 0.797132 -0.000000
    outer loop
      vertex -28.580736 -8.678329 17.000000
      vertex -28.580736 -8.678329 19.000000
      vertex -28.139555 -9.012512 19.000000
    endloop
  endfacet
  facet normal 0.642786 0.766045 -0.000000
    outer loop
      vertex -28.580736 -8.678329 17.000000
      vertex -29.004713 -8.322572 19.000000
      vertex -28.580736 -8.678329 19.000000
    endloop
  endfacet
  facet normal 0.642786 0.766045 0.000000
    outer loop
      vertex -28.580736 -8.678329 17.000000
      vertex -29.004713 -8.322572 17.000000
      vertex -29.004713 -8.322572 19.000000
    endloop
  endfacet
  facet normal 0.603805 0.797132 -0.000000
    outer loop
      vertex -28.139555 -9.012512 17.000000
      vertex -28.580736 -8.678329 17.000000
      vertex -28.139555 -9.012512 19.000000
    endloop
  endfacet
  facet normal 0.521434 0.853292 -0.000000
    outer loop
      vertex -27.682264 -9.324287 17.000000
      vertex -27.682264 -9.324287 19.000000
      vertex -27.209999 -9.612882 19.000000
    endloop
  endfacet
  facet normal 0.563320 0.826239 -0.000000
    outer loop
      vertex -27.682264 -9.324287 17.000000
      vertex -28.139555 -9.012512 19.000000
      vertex -27.682264 -9.324287 19.000000
    endloop
  endfacet
  facet normal 0.563320 0.826239 0.000000
    outer loop
      vertex -27.682264 -9.324287 17.000000
      vertex -28.139555 -9.012512 17.000000
      vertex -28.139555 -9.012512 19.000000
    endloop
  endfacet
  facet normal 0.521434 0.853292 -0.000000
    outer loop
      vertex -27.209999 -9.612882 17.000000
      vertex -27.682264 -9.324287 17.000000
      vertex -27.209999 -9.612882 19.000000
    endloop
  endfacet
  facet normal 0.433884 0.900969 -0.000000
    outer loop
      vertex -26.723938 -9.877577 17.000000
      vertex -26.723938 -9.877577 19.000000
      vertex -26.225286 -10.117715 19.000000
    endloop
  endfacet
  facet normal 0.478254 0.878221 -0.000000
    outer loop
      vertex -26.723938 -9.877577 17.000000
      vertex -27.209999 -9.612882 19.000000
      vertex -26.723938 -9.877577 19.000000
    endloop
  endfacet
  facet normal 0.478254 0.878221 0.000000
    outer loop
      vertex -26.723938 -9.877577 17.000000
      vertex -27.209999 -9.612882 17.000000
      vertex -27.209999 -9.612882 19.000000
    endloop
  endfacet
  facet normal 0.433884 0.900969 -0.000000
    outer loop
      vertex -26.225286 -10.117715 17.000000
      vertex -26.723938 -9.877577 17.000000
      vertex -26.225286 -10.117715 19.000000
    endloop
  endfacet
  facet normal 0.388436 0.921476 0.000000
    outer loop
      vertex -25.715286 -10.332699 17.000000
      vertex -26.225286 -10.117715 17.000000
      vertex -26.225286 -10.117715 19.000000
    endloop
  endfacet
  facet normal 0.388436 0.921476 -0.000000
    outer loop
      vertex -25.715286 -10.332699 17.000000
      vertex -26.225286 -10.117715 19.000000
      vertex -25.715286 -10.332699 19.000000
    endloop
  endfacet
  facet normal 0.342019 0.939693 0.000000
    outer loop
      vertex -25.195202 -10.521994 17.000000
      vertex -25.715286 -10.332699 17.000000
      vertex -25.715286 -10.332699 19.000000
    endloop
  endfacet
  facet normal 0.294755 0.955573 -0.000000
    outer loop
      vertex -25.195202 -10.521994 17.000000
      vertex -25.195202 -10.521994 19.000000
      vertex -24.666328 -10.685129 19.000000
    endloop
  endfacet
  facet normal 0.342019 0.939693 -0.000000
    outer loop
      vertex -25.195202 -10.521994 17.000000
      vertex -25.715286 -10.332699 19.000000
      vertex -25.195202 -10.521994 19.000000
    endloop
  endfacet
  facet normal 0.294755 0.955573 -0.000000
    outer loop
      vertex -24.666328 -10.685129 17.000000
      vertex -25.195202 -10.521994 17.000000
      vertex -24.666328 -10.685129 19.000000
    endloop
  endfacet
  facet normal 0.246758 0.969077 0.000000
    outer loop
      vertex -24.129982 -10.821700 17.000000
      vertex -24.666328 -10.685129 17.000000
      vertex -24.666328 -10.685129 19.000000
    endloop
  endfacet
  facet normal 0.246758 0.969077 -0.000000
    outer loop
      vertex -24.129982 -10.821700 17.000000
      vertex -24.666328 -10.685129 19.000000
      vertex -24.129982 -10.821700 19.000000
    endloop
  endfacet
  facet normal 0.198145 0.980173 0.000000
    outer loop
      vertex -23.587494 -10.931366 17.000000
      vertex -24.129982 -10.821700 17.000000
      vertex -24.129982 -10.821700 19.000000
    endloop
  endfacet
  facet normal 0.198145 0.980173 -0.000000
    outer loop
      vertex -23.587494 -10.931366 17.000000
      vertex -24.129982 -10.821700 19.000000
      vertex -23.587494 -10.931366 19.000000
    endloop
  endfacet
  facet normal 0.149042 0.988831 0.000000
    outer loop
      vertex -23.040215 -11.013855 17.000000
      vertex -23.587494 -10.931366 17.000000
      vertex -23.587494 -10.931366 19.000000
    endloop
  endfacet
  facet normal 0.099568 0.995031 -0.000000
    outer loop
      vertex -23.040215 -11.013855 17.000000
      vertex -23.040215 -11.013855 19.000000
      vertex -22.489504 -11.068962 19.000000
    endloop
  endfacet
  facet normal 0.149042 0.988831 -0.000000
    outer loop
      vertex -23.040215 -11.013855 17.000000
      vertex -23.587494 -10.931366 19.000000
      vertex -23.040215 -11.013855 19.000000
    endloop
  endfacet
  facet normal 0.099568 0.995031 -0.000000
    outer loop
      vertex -22.489504 -11.068962 17.000000
      vertex -23.040215 -11.013855 17.000000
      vertex -22.489504 -11.068962 19.000000
    endloop
  endfacet
  facet normal 0.049846 0.998757 0.000000
    outer loop
      vertex -21.936731 -11.096550 17.000000
      vertex -22.489504 -11.068962 17.000000
      vertex -22.489504 -11.068962 19.000000
    endloop
  endfacet
  facet normal 0.000000 1.000000 0.000000
    outer loop
      vertex -21.936731 -11.096550 17.000000
      vertex -21.936731 -11.096550 19.000000
      vertex -21.383270 -11.096550 19.000000
    endloop
  endfacet
  facet normal 0.049846 0.998757 -0.000000
    outer loop
      vertex -21.936731 -11.096550 17.000000
      vertex -22.489504 -11.068962 19.000000
      vertex -21.936731 -11.096550 19.000000
    endloop
  endfacet
  facet normal 0.000000 1.000000 -0.000000
    outer loop
      vertex -21.383270 -11.096550 17.000000
      vertex -21.936731 -11.096550 17.000000
      vertex -21.383270 -11.096550 19.000000
    endloop
  endfacet
  facet normal -0.049846 0.998757 0.000000
    outer loop
      vertex -20.830496 -11.068962 17.000000
      vertex -21.383270 -11.096550 17.000000
      vertex -21.383270 -11.096550 19.000000
    endloop
  endfacet
  facet normal -0.049846 0.998757 0.000000
    outer loop
      vertex -20.830496 -11.068962 17.000000
      vertex -21.383270 -11.096550 19.000000
      vertex -20.830496 -11.068962 19.000000
    endloop
  endfacet
  facet normal -0.099568 0.995031 0.000000
    outer loop
      vertex -20.279785 -11.013855 17.000000
      vertex -20.830496 -11.068962 17.000000
      vertex -20.830496 -11.068962 19.000000
    endloop
  endfacet
  facet normal -0.099568 0.995031 0.000000
    outer loop
      vertex -20.279785 -11.013855 17.000000
      vertex -20.830496 -11.068962 19.000000
      vertex -20.279785 -11.013855 19.000000
    endloop
  endfacet
  facet normal -0.149042 0.988831 0.000000
    outer loop
      vertex -19.732506 -10.931366 17.000000
      vertex -20.279785 -11.013855 17.000000
      vertex -20.279785 -11.013855 19.000000
    endloop
  endfacet
  facet normal -0.198145 0.980173 0.000000
    outer loop
      vertex -19.732506 -10.931366 17.000000
      vertex -19.732506 -10.931366 19.000000
      vertex -19.190018 -10.821700 19.000000
    endloop
  endfacet
  facet normal -0.149042 0.988831 0.000000
    outer loop
      vertex -19.732506 -10.931366 17.000000
      vertex -20.279785 -11.013855 19.000000
      vertex -19.732506 -10.931366 19.000000
    endloop
  endfacet
  facet normal -0.198145 0.980173 0.000000
    outer loop
      vertex -19.190018 -10.821700 17.000000
      vertex -19.732506 -10.931366 17.000000
      vertex -19.190018 -10.821700 19.000000
    endloop
  endfacet
  facet normal -0.246758 0.969077 0.000000
    outer loop
      vertex -18.653671 -10.685129 17.000000
      vertex -19.190018 -10.821700 17.000000
      vertex -19.190018 -10.821700 19.000000
    endloop
  endfacet
  facet normal -0.294755 0.955573 0.000000
    outer loop
      vertex -18.653671 -10.685129 17.000000
      vertex -18.653671 -10.685129 19.000000
      vertex -18.124798 -10.521994 19.000000
    endloop
  endfacet
  facet normal -0.246758 0.969077 0.000000
    outer loop
      vertex -18.653671 -10.685129 17.000000
      vertex -19.190018 -10.821700 19.000000
      vertex -18.653671 -10.685129 19.000000
    endloop
  endfacet
  facet normal -0.294755 0.955573 0.000000
    outer loop
      vertex -18.124798 -10.521994 17.000000
      vertex -18.653671 -10.685129 17.000000
      vertex -18.124798 -10.521994 19.000000
    endloop
  endfacet
  facet normal -0.388435 0.921476 0.000000
    outer loop
      vertex -17.604715 -10.332699 17.000000
      vertex -17.604715 -10.332699 19.000000
      vertex -17.094713 -10.117715 19.000000
    endloop
  endfacet
  facet normal -0.342021 0.939692 0.000000
    outer loop
      vertex -17.604715 -10.332699 17.000000
      vertex -18.124798 -10.521994 19.000000
      vertex -17.604715 -10.332699 19.000000
    endloop
  endfacet
  facet normal -0.342021 0.939692 0.000000
    outer loop
      vertex -17.604715 -10.332699 17.000000
      vertex -18.124798 -10.521994 17.000000
      vertex -18.124798 -10.521994 19.000000
    endloop
  endfacet
  facet normal -0.388435 0.921476 0.000000
    outer loop
      vertex -17.094713 -10.117715 17.000000
      vertex -17.604715 -10.332699 17.000000
      vertex -17.094713 -10.117715 19.000000
    endloop
  endfacet
  facet normal -0.478254 0.878221 0.000000
    outer loop
      vertex -16.596062 -9.877577 17.000000
      vertex -16.596062 -9.877577 19.000000
      vertex -16.110001 -9.612882 19.000000
    endloop
  endfacet
  facet normal -0.433884 0.900969 0.000000
    outer loop
      vertex -16.596062 -9.877577 17.000000
      vertex -17.094713 -10.117715 19.000000
      vertex -16.596062 -9.877577 19.000000
    endloop
  endfacet
  facet normal -0.433884 0.900969 0.000000
    outer loop
      vertex -16.596062 -9.877577 17.000000
      vertex -17.094713 -10.117715 17.000000
      vertex -17.094713 -10.117715 19.000000
    endloop
  endfacet
  facet normal -0.478254 0.878221 0.000000
    outer loop
      vertex -16.110001 -9.612882 17.000000
      vertex -16.596062 -9.877577 17.000000
      vertex -16.110001 -9.612882 19.000000
    endloop
  endfacet
  facet normal -0.521435 0.853291 0.000000
    outer loop
      vertex -15.637736 -9.324287 17.000000
      vertex -16.110001 -9.612882 19.000000
      vertex -15.637736 -9.324287 19.000000
    endloop
  endfacet
  facet normal -0.521435 0.853291 0.000000
    outer loop
      vertex -15.637736 -9.324287 17.000000
      vertex -16.110001 -9.612882 17.000000
      vertex -16.110001 -9.612882 19.000000
    endloop
  endfacet
  facet normal -0.563320 0.826239 0.000000
    outer loop
      vertex -15.180446 -9.012512 17.000000
      vertex -15.637736 -9.324287 19.000000
      vertex -15.180446 -9.012512 19.000000
    endloop
  endfacet
  facet normal -0.563320 0.826239 0.000000
    outer loop
      vertex -15.180446 -9.012512 17.000000
      vertex -15.637736 -9.324287 17.000000
      vertex -15.637736 -9.324287 19.000000
    endloop
  endfacet
  facet normal -0.603805 0.797132 0.000000
    outer loop
      vertex -14.739264 -8.678329 17.000000
      vertex -15.180446 -9.012512 19.000000
      vertex -14.739264 -8.678329 19.000000
    endloop
  endfacet
  facet normal -0.603805 0.797132 0.000000
    outer loop
      vertex -14.739264 -8.678329 17.000000
      vertex -15.180446 -9.012512 17.000000
      vertex -15.180446 -9.012512 19.000000
    endloop
  endfacet
  facet normal -0.642787 0.766045 0.000000
    outer loop
      vertex -14.315288 -8.322572 17.000000
      vertex -14.739264 -8.678329 19.000000
      vertex -14.315288 -8.322572 19.000000
    endloop
  endfacet
  facet normal -0.642787 0.766045 0.000000
    outer loop
      vertex -14.315288 -8.322572 17.000000
      vertex -14.739264 -8.678329 17.000000
      vertex -14.739264 -8.678329 19.000000
    endloop
  endfacet
  facet normal -0.680173 0.733052 0.000000
    outer loop
      vertex -13.909572 -7.946122 17.000000
      vertex -14.315288 -8.322572 19.000000
      vertex -13.909572 -7.946122 19.000000
    endloop
  endfacet
  facet normal -0.680173 0.733052 0.000000
    outer loop
      vertex -13.909572 -7.946122 17.000000
      vertex -14.315288 -8.322572 17.000000
      vertex -14.315288 -8.322572 19.000000
    endloop
  endfacet
  facet normal -0.715867 0.698236 0.000000
    outer loop
      vertex -13.523125 -7.549917 17.000000
      vertex -13.909572 -7.946122 19.000000
      vertex -13.523125 -7.549917 19.000000
    endloop
  endfacet
  facet normal -0.715867 0.698236 0.000000
    outer loop
      vertex -13.523125 -7.549917 17.000000
      vertex -13.909572 -7.946122 17.000000
      vertex -13.909572 -7.946122 19.000000
    endloop
  endfacet
  facet normal -0.749781 0.661686 0.000000
    outer loop
      vertex -13.156907 -7.134943 17.000000
      vertex -13.523125 -7.549917 19.000000
      vertex -13.156907 -7.134943 19.000000
    endloop
  endfacet
  facet normal -0.749781 0.661686 0.000000
    outer loop
      vertex -13.156907 -7.134943 17.000000
      vertex -13.523125 -7.549917 17.000000
      vertex -13.523125 -7.549917 19.000000
    endloop
  endfacet
  facet normal -0.781831 0.623490 0.000000
    outer loop
      vertex -12.811830 -6.702229 17.000000
      vertex -13.156907 -7.134943 17.000000
      vertex -13.156907 -7.134943 19.000000
    endloop
  endfacet
  facet normal -0.811938 0.583744 0.000000
    outer loop
      vertex -12.811830 -6.702229 17.000000
      vertex -12.811830 -6.702229 19.000000
      vertex -12.488750 -6.252852 19.000000
    endloop
  endfacet
  facet normal -0.781831 0.623490 0.000000
    outer loop
      vertex -12.811830 -6.702229 17.000000
      vertex -13.156907 -7.134943 19.000000
      vertex -12.811830 -6.702229 19.000000
    endloop
  endfacet
  facet normal -0.811938 0.583744 0.000000
    outer loop
      vertex -12.488750 -6.252852 17.000000
      vertex -12.811830 -6.702229 17.000000
      vertex -12.488750 -6.252852 19.000000
    endloop
  endfacet
  facet normal -0.840025 0.542547 0.000000
    outer loop
      vertex -12.188471 -5.787931 17.000000
      vertex -12.488750 -6.252852 17.000000
      vertex -12.488750 -6.252852 19.000000
    endloop
  endfacet
  facet normal -0.840025 0.542547 0.000000
    outer loop
      vertex -12.188471 -5.787931 17.000000
      vertex -12.488750 -6.252852 19.000000
      vertex -12.188471 -5.787931 19.000000
    endloop
  endfacet
  facet normal -0.866026 0.500000 0.000000
    outer loop
      vertex -11.911740 -5.308619 17.000000
      vertex -12.188471 -5.787931 17.000000
      vertex -12.188471 -5.787931 19.000000
    endloop
  endfacet
  facet normal -0.889872 0.456211 0.000000
    outer loop
      vertex -11.911740 -5.308619 17.000000
      vertex -11.911740 -5.308619 19.000000
      vertex -11.659245 -4.816110 19.000000
    endloop
  endfacet
  facet normal -0.866026 0.500000 0.000000
    outer loop
      vertex -11.911740 -5.308619 17.000000
      vertex -12.188471 -5.787931 19.000000
      vertex -11.911740 -5.308619 19.000000
    endloop
  endfacet
  facet normal -0.889872 0.456211 0.000000
    outer loop
      vertex -11.659245 -4.816110 17.000000
      vertex -11.911740 -5.308619 17.000000
      vertex -11.659245 -4.816110 19.000000
    endloop
  endfacet
  facet normal -0.911506 0.411287 0.000000
    outer loop
      vertex -11.431614 -4.311626 17.000000
      vertex -11.659245 -4.816110 17.000000
      vertex -11.659245 -4.816110 19.000000
    endloop
  endfacet
  facet normal -0.930874 0.365340 0.000000
    outer loop
      vertex -11.431614 -4.311626 17.000000
      vertex -11.431614 -4.311626 19.000000
      vertex -11.229412 -3.796424 19.000000
    endloop
  endfacet
  facet normal -0.911506 0.411287 0.000000
    outer loop
      vertex -11.431614 -4.311626 17.000000
      vertex -11.659245 -4.816110 19.000000
      vertex -11.431614 -4.311626 19.000000
    endloop
  endfacet
  facet normal -0.930874 0.365340 0.000000
    outer loop
      vertex -11.229412 -3.796424 17.000000
      vertex -11.431614 -4.311626 17.000000
      vertex -11.229412 -3.796424 19.000000
    endloop
  endfacet
  facet normal -0.947927 0.318487 0.000000
    outer loop
      vertex -11.053142 -3.271782 17.000000
      vertex -11.229412 -3.796424 17.000000
      vertex -11.229412 -3.796424 19.000000
    endloop
  endfacet
  facet normal -0.947927 0.318487 0.000000
    outer loop
      vertex -11.053142 -3.271782 17.000000
      vertex -11.229412 -3.796424 19.000000
      vertex -11.053142 -3.271782 19.000000
    endloop
  endfacet
  facet normal -0.974928 0.222521 0.000000
    outer loop
      vertex -10.903242 -2.739007 17.000000
      vertex -10.903242 -2.739007 19.000000
      vertex -10.780086 -2.199422 19.000000
    endloop
  endfacet
  facet normal -0.962624 0.270840 0.000000
    outer loop
      vertex -10.903242 -2.739007 17.000000
      vertex -11.053142 -3.271782 19.000000
      vertex -10.903242 -2.739007 19.000000
    endloop
  endfacet
  facet normal -0.962624 0.270840 0.000000
    outer loop
      vertex -10.903242 -2.739007 17.000000
      vertex -11.053142 -3.271782 17.000000
      vertex -11.053142 -3.271782 19.000000
    endloop
  endfacet
  facet normal -0.974928 0.222521 0.000000
    outer loop
      vertex -10.780086 -2.199422 17.000000
      vertex -10.903242 -2.739007 17.000000
      vertex -10.780086 -2.199422 19.000000
    endloop
  endfacet
  facet normal -0.984808 0.173648 0.000000
    outer loop
      vertex -10.683978 -1.654369 17.000000
      vertex -10.780086 -2.199422 19.000000
      vertex -10.683978 -1.654369 19.000000
    endloop
  endfacet
  facet normal -0.984808 0.173648 0.000000
    outer loop
      vertex -10.683978 -1.654369 17.000000
      vertex -10.780086 -2.199422 17.000000
      vertex -10.780086 -2.199422 19.000000
    endloop
  endfacet
  facet normal -0.992239 0.124345 0.000000
    outer loop
      vertex -10.615158 -1.105203 17.000000
      vertex -10.683978 -1.654369 19.000000
      vertex -10.615158 -1.105203 19.000000
    endloop
  endfacet
  facet normal -0.992239 0.124345 0.000000
    outer loop
      vertex -10.615158 -1.105203 17.000000
      vertex -10.683978 -1.654369 17.000000
      vertex -10.683978 -1.654369 19.000000
    endloop
  endfacet
  facet normal -0.997204 0.074730 0.000000
    outer loop
      vertex -10.573798 -0.553289 17.000000
      vertex -10.615158 -1.105203 19.000000
      vertex -10.573798 -0.553289 19.000000
    endloop
  endfacet
  facet normal -0.997204 0.074730 0.000000
    outer loop
      vertex -10.573798 -0.553289 17.000000
      vertex -10.615158 -1.105203 17.000000
      vertex -10.615158 -1.105203 19.000000
    endloop
  endfacet
  facet normal -0.999689 0.024930 0.000000
    outer loop
      vertex -10.560000 0.000000 17.000000
      vertex -10.573798 -0.553289 19.000000
      vertex -10.560000 0.000000 19.000000
    endloop
  endfacet
  facet normal -0.999689 0.024930 0.000000
    outer loop
      vertex -10.560000 0.000000 17.000000
      vertex -10.573798 -0.553289 17.000000
      vertex -10.573798 -0.553289 19.000000
    endloop
  endfacet
  facet normal -0.999689 -0.024930 0.000000
    outer loop
      vertex 32.745201 0.553289 17.000000
      vertex 32.758999 0.000000 17.000000
      vertex 32.758999 0.000000 19.000000
    endloop
  endfacet
  facet normal -0.999689 -0.024930 0.000000
    outer loop
      vertex 32.745201 0.553289 17.000000
      vertex 32.758999 0.000000 19.000000
      vertex 32.745201 0.553289 19.000000
    endloop
  endfacet
  facet normal -0.997204 -0.074728 0.000000
    outer loop
      vertex 32.703842 1.105203 17.000000
      vertex 32.745201 0.553289 19.000000
      vertex 32.703842 1.105203 19.000000
    endloop
  endfacet
  facet normal -0.997204 -0.074728 0.000000
    outer loop
      vertex 32.703842 1.105203 17.000000
      vertex 32.745201 0.553289 17.000000
      vertex 32.745201 0.553289 19.000000
    endloop
  endfacet
  facet normal -0.992239 -0.124346 0.000000
    outer loop
      vertex 32.635021 1.654369 17.000000
      vertex 32.703842 1.105203 19.000000
      vertex 32.635021 1.654369 19.000000
    endloop
  endfacet
  facet normal -0.992239 -0.124346 0.000000
    outer loop
      vertex 32.635021 1.654369 17.000000
      vertex 32.703842 1.105203 17.000000
      vertex 32.703842 1.105203 19.000000
    endloop
  endfacet
  facet normal -0.984808 -0.173648 0.000000
    outer loop
      vertex 32.538914 2.199422 17.000000
      vertex 32.635021 1.654369 19.000000
      vertex 32.538914 2.199422 19.000000
    endloop
  endfacet
  facet normal -0.984808 -0.173648 0.000000
    outer loop
      vertex 32.538914 2.199422 17.000000
      vertex 32.635021 1.654369 17.000000
      vertex 32.635021 1.654369 19.000000
    endloop
  endfacet
  facet normal -0.974928 -0.222522 0.000000
    outer loop
      vertex 32.415756 2.739007 17.000000
      vertex 32.538914 2.199422 19.000000
      vertex 32.415756 2.739007 19.000000
    endloop
  endfacet
  facet normal -0.974928 -0.222522 0.000000
    outer loop
      vertex 32.415756 2.739007 17.000000
      vertex 32.538914 2.199422 17.000000
      vertex 32.538914 2.199422 19.000000
    endloop
  endfacet
  facet normal -0.962625 -0.270838 0.000000
    outer loop
      vertex 32.265858 3.271782 17.000000
      vertex 32.415756 2.739007 19.000000
      vertex 32.265858 3.271782 19.000000
    endloop
  endfacet
  facet normal -0.962625 -0.270838 0.000000
    outer loop
      vertex 32.265858 3.271782 17.000000
      vertex 32.415756 2.739007 17.000000
      vertex 32.415756 2.739007 19.000000
    endloop
  endfacet
  facet normal -0.947928 -0.318486 0.000000
    outer loop
      vertex 32.089588 3.796424 17.000000
      vertex 32.265858 3.271782 19.000000
      vertex 32.089588 3.796424 19.000000
    endloop
  endfacet
  facet normal -0.947928 -0.318486 0.000000
    outer loop
      vertex 32.089588 3.796424 17.000000
      vertex 32.265858 3.271782 17.000000
      vertex 32.265858 3.271782 19.000000
    endloop
  endfacet
  facet normal -0.930874 -0.365340 0.000000
    outer loop
      vertex 31.887386 4.311626 17.000000
      vertex 32.089588 3.796424 19.000000
      vertex 31.887386 4.311626 19.000000
    endloop
  endfacet
  facet normal -0.930874 -0.365340 0.000000
    outer loop
      vertex 31.887386 4.311626 17.000000
      vertex 32.089588 3.796424 17.000000
      vertex 32.089588 3.796424 19.000000
    endloop
  endfacet
  facet normal -0.911505 -0.411289 0.000000
    outer loop
      vertex 31.659754 4.816110 17.000000
      vertex 31.887386 4.311626 19.000000
      vertex 31.659754 4.816110 19.000000
    endloop
  endfacet
  facet normal -0.911505 -0.411289 0.000000
    outer loop
      vertex 31.659754 4.816110 17.000000
      vertex 31.887386 4.311626 17.000000
      vertex 31.887386 4.311626 19.000000
    endloop
  endfacet
  facet normal -0.889872 -0.456211 0.000000
    outer loop
      vertex 31.407259 5.308619 17.000000
      vertex 31.659754 4.816110 19.000000
      vertex 31.407259 5.308619 19.000000
    endloop
  endfacet
  facet normal -0.889872 -0.456211 0.000000
    outer loop
      vertex 31.407259 5.308619 17.000000
      vertex 31.659754 4.816110 17.000000
      vertex 31.659754 4.816110 19.000000
    endloop
  endfacet
  facet normal -0.866026 -0.499998 0.000000
    outer loop
      vertex 31.130529 5.787931 17.000000
      vertex 31.407259 5.308619 17.000000
      vertex 31.407259 5.308619 19.000000
    endloop
  endfacet
  facet normal -0.866026 -0.499998 0.000000
    outer loop
      vertex 31.130529 5.787931 17.000000
      vertex 31.407259 5.308619 19.000000
      vertex 31.130529 5.787931 19.000000
    endloop
  endfacet
  facet normal -0.840025 -0.542548 0.000000
    outer loop
      vertex 30.830250 6.252852 17.000000
      vertex 31.130529 5.787931 17.000000
      vertex 31.130529 5.787931 19.000000
    endloop
  endfacet
  facet normal -0.840025 -0.542548 0.000000
    outer loop
      vertex 30.830250 6.252852 17.000000
      vertex 31.130529 5.787931 19.000000
      vertex 30.830250 6.252852 19.000000
    endloop
  endfacet
  facet normal -0.811939 -0.583742 0.000000
    outer loop
      vertex 30.507172 6.702229 17.000000
      vertex 30.830250 6.252852 17.000000
      vertex 30.830250 6.252852 19.000000
    endloop
  endfacet
  facet normal -0.811939 -0.583742 0.000000
    outer loop
      vertex 30.507172 6.702229 17.000000
      vertex 30.830250 6.252852 19.000000
      vertex 30.507172 6.702229 19.000000
    endloop
  endfacet
  facet normal -0.781831 -0.623490 0.000000
    outer loop
      vertex 30.162094 7.134943 17.000000
      vertex 30.507172 6.702229 17.000000
      vertex 30.507172 6.702229 19.000000
    endloop
  endfacet
  facet normal -0.781831 -0.623490 0.000000
    outer loop
      vertex 30.162094 7.134943 17.000000
      vertex 30.507172 6.702229 19.000000
      vertex 30.162094 7.134943 19.000000
    endloop
  endfacet
  facet normal -0.749780 -0.661687 0.000000
    outer loop
      vertex 29.795876 7.549917 17.000000
      vertex 30.162094 7.134943 17.000000
      vertex 30.162094 7.134943 19.000000
    endloop
  endfacet
  facet normal -0.749780 -0.661687 0.000000
    outer loop
      vertex 29.795876 7.549917 17.000000
      vertex 30.162094 7.134943 19.000000
      vertex 29.795876 7.549917 19.000000
    endloop
  endfacet
  facet normal -0.715868 -0.698236 0.000000
    outer loop
      vertex 29.409430 7.946122 17.000000
      vertex 29.795876 7.549917 17.000000
      vertex 29.795876 7.549917 19.000000
    endloop
  endfacet
  facet normal -0.715868 -0.698236 0.000000
    outer loop
      vertex 29.409430 7.946122 17.000000
      vertex 29.795876 7.549917 19.000000
      vertex 29.409430 7.946122 19.000000
    endloop
  endfacet
  facet normal -0.680173 -0.733052 0.000000
    outer loop
      vertex 29.003714 8.322572 17.000000
      vertex 29.409430 7.946122 17.000000
      vertex 29.409430 7.946122 19.000000
    endloop
  endfacet
  facet normal -0.680173 -0.733052 0.000000
    outer loop
      vertex 29.003714 8.322572 17.000000
      vertex 29.409430 7.946122 19.000000
      vertex 29.003714 8.322572 19.000000
    endloop
  endfacet
  facet normal -0.642786 -0.766045 0.000000
    outer loop
      vertex 28.579737 8.678329 17.000000
      vertex 29.003714 8.322572 17.000000
      vertex 29.003714 8.322572 19.000000
    endloop
  endfacet
  facet normal -0.642786 -0.766045 0.000000
    outer loop
      vertex 28.579737 8.678329 17.000000
      vertex 29.003714 8.322572 19.000000
      vertex 28.579737 8.678329 19.000000
    endloop
  endfacet
  facet normal -0.603805 -0.797132 0.000000
    outer loop
      vertex 28.138556 9.012512 17.000000
      vertex 28.579737 8.678329 19.000000
      vertex 28.138556 9.012512 19.000000
    endloop
  endfacet
  facet normal -0.603805 -0.797132 0.000000
    outer loop
      vertex 28.138556 9.012512 17.000000
      vertex 28.579737 8.678329 17.000000
      vertex 28.579737 8.678329 19.000000
    endloop
  endfacet
  facet normal -0.563318 -0.826240 0.000000
    outer loop
      vertex 27.681263 9.324287 17.000000
      vertex 28.138556 9.012512 19.000000
      vertex 27.681263 9.324287 19.000000
    endloop
  endfacet
  facet normal -0.563318 -0.826240 0.000000
    outer loop
      vertex 27.681263 9.324287 17.000000
      vertex 28.138556 9.012512 17.000000
      vertex 28.138556 9.012512 19.000000
    endloop
  endfacet
  facet normal -0.521435 -0.853291 0.000000
    outer loop
      vertex 27.209000 9.612882 17.000000
      vertex 27.681263 9.324287 19.000000
      vertex 27.209000 9.612882 19.000000
    endloop
  endfacet
  facet normal -0.521435 -0.853291 0.000000
    outer loop
      vertex 27.209000 9.612882 17.000000
      vertex 27.681263 9.324287 17.000000
      vertex 27.681263 9.324287 19.000000
    endloop
  endfacet
  facet normal -0.478254 -0.878221 0.000000
    outer loop
      vertex 26.722939 9.877577 17.000000
      vertex 27.209000 9.612882 19.000000
      vertex 26.722939 9.877577 19.000000
    endloop
  endfacet
  facet normal -0.478254 -0.878221 0.000000
    outer loop
      vertex 26.722939 9.877577 17.000000
      vertex 27.209000 9.612882 17.000000
      vertex 27.209000 9.612882 19.000000
    endloop
  endfacet
  facet normal -0.433884 -0.900969 0.000000
    outer loop
      vertex 26.224287 10.117715 17.000000
      vertex 26.722939 9.877577 19.000000
      vertex 26.224287 10.117715 19.000000
    endloop
  endfacet
  facet normal -0.433884 -0.900969 0.000000
    outer loop
      vertex 26.224287 10.117715 17.000000
      vertex 26.722939 9.877577 17.000000
      vertex 26.722939 9.877577 19.000000
    endloop
  endfacet
  facet normal -0.388435 -0.921476 0.000000
    outer loop
      vertex 25.714285 10.332699 17.000000
      vertex 26.224287 10.117715 19.000000
      vertex 25.714285 10.332699 19.000000
    endloop
  endfacet
  facet normal -0.388435 -0.921476 0.000000
    outer loop
      vertex 25.714285 10.332699 17.000000
      vertex 26.224287 10.117715 17.000000
      vertex 26.224287 10.117715 19.000000
    endloop
  endfacet
  facet normal -0.294755 -0.955573 0.000000
    outer loop
      vertex 25.194202 10.521994 17.000000
      vertex 25.194202 10.521994 19.000000
      vertex 24.665329 10.685129 19.000000
    endloop
  endfacet
  facet normal -0.342021 -0.939692 0.000000
    outer loop
      vertex 25.194202 10.521994 17.000000
      vertex 25.714285 10.332699 19.000000
      vertex 25.194202 10.521994 19.000000
    endloop
  endfacet
  facet normal -0.342021 -0.939692 0.000000
    outer loop
      vertex 25.194202 10.521994 17.000000
      vertex 25.714285 10.332699 17.000000
      vertex 25.714285 10.332699 19.000000
    endloop
  endfacet
  facet normal -0.294755 -0.955573 0.000000
    outer loop
      vertex 24.665329 10.685129 17.000000
      vertex 25.194202 10.521994 17.000000
      vertex 24.665329 10.685129 19.000000
    endloop
  endfacet
  facet normal -0.198145 -0.980173 0.000000
    outer loop
      vertex 24.128983 10.821700 17.000000
      vertex 24.128983 10.821700 19.000000
      vertex 23.586494 10.931366 19.000000
    endloop
  endfacet
  facet normal -0.246758 -0.969077 0.000000
    outer loop
      vertex 24.128983 10.821700 17.000000
      vertex 24.665329 10.685129 19.000000
      vertex 24.128983 10.821700 19.000000
    endloop
  endfacet
  facet normal -0.246758 -0.969077 0.000000
    outer loop
      vertex 24.128983 10.821700 17.000000
      vertex 24.665329 10.685129 17.000000
      vertex 24.665329 10.685129 19.000000
    endloop
  endfacet
  facet normal -0.198145 -0.980173 0.000000
    outer loop
      vertex 23.586494 10.931366 17.000000
      vertex 24.128983 10.821700 17.000000
      vertex 23.586494 10.931366 19.000000
    endloop
  endfacet
  facet normal -0.149042 -0.988831 0.000000
    outer loop
      vertex 23.039215 11.013855 17.000000
      vertex 23.586494 10.931366 19.000000
      vertex 23.039215 11.013855 19.000000
    endloop
  endfacet
  facet normal -0.149042 -0.988831 0.000000
    outer loop
      vertex 23.039215 11.013855 17.000000
      vertex 23.586494 10.931366 17.000000
      vertex 23.586494 10.931366 19.000000
    endloop
  endfacet
  facet normal -0.099568 -0.995031 0.000000
    outer loop
      vertex 22.488504 11.068962 17.000000
      vertex 23.039215 11.013855 19.000000
      vertex 22.488504 11.068962 19.000000
    endloop
  endfacet
  facet normal -0.099568 -0.995031 0.000000
    outer loop
      vertex 22.488504 11.068962 17.000000
      vertex 23.039215 11.013855 17.000000
      vertex 23.039215 11.013855 19.000000
    endloop
  endfacet
  facet normal -0.049846 -0.998757 0.000000
    outer loop
      vertex 21.935730 11.096550 17.000000
      vertex 22.488504 11.068962 19.000000
      vertex 21.935730 11.096550 19.000000
    endloop
  endfacet
  facet normal -0.049846 -0.998757 0.000000
    outer loop
      vertex 21.935730 11.096550 17.000000
      vertex 22.488504 11.068962 17.000000
      vertex 22.488504 11.068962 19.000000
    endloop
  endfacet
  facet normal 0.000000 -1.000000 0.000000
    outer loop
      vertex 21.382269 11.096550 17.000000
      vertex 21.935730 11.096550 19.000000
      vertex 21.382269 11.096550 19.000000
    endloop
  endfacet
  facet normal 0.000000 -1.000000 0.000000
    outer loop
      vertex 21.382269 11.096550 17.000000
      vertex 21.935730 11.096550 17.000000
      vertex 21.935730 11.096550 19.000000
    endloop
  endfacet
  facet normal 0.099568 -0.995031 0.000000
    outer loop
      vertex 20.829496 11.068962 17.000000
      vertex 20.829496 11.068962 19.000000
      vertex 20.278786 11.013855 19.000000
    endloop
  endfacet
  facet normal 0.049846 -0.998757 0.000000
    outer loop
      vertex 20.829496 11.068962 17.000000
      vertex 21.382269 11.096550 19.000000
      vertex 20.829496 11.068962 19.000000
    endloop
  endfacet
  facet normal 0.049846 -0.998757 0.000000
    outer loop
      vertex 20.829496 11.068962 17.000000
      vertex 21.382269 11.096550 17.000000
      vertex 21.382269 11.096550 19.000000
    endloop
  endfacet
  facet normal 0.099568 -0.995031 0.000000
    outer loop
      vertex 20.278786 11.013855 17.000000
      vertex 20.829496 11.068962 17.000000
      vertex 20.278786 11.013855 19.000000
    endloop
  endfacet
  facet normal 0.198146 -0.980173 0.000000
    outer loop
      vertex 19.731504 10.931366 17.000000
      vertex 19.731504 10.931366 19.000000
      vertex 19.189018 10.821700 19.000000
    endloop
  endfacet
  facet normal 0.149042 -0.988831 0.000000
    outer loop
      vertex 19.731504 10.931366 17.000000
      vertex 20.278786 11.013855 19.000000
      vertex 19.731504 10.931366 19.000000
    endloop
  endfacet
  facet normal 0.149042 -0.988831 0.000000
    outer loop
      vertex 19.731504 10.931366 17.000000
      vertex 20.278786 11.013855 17.000000
      vertex 20.278786 11.013855 19.000000
    endloop
  endfacet
  facet normal 0.198146 -0.980173 0.000000
    outer loop
      vertex 19.189018 10.821700 17.000000
      vertex 19.731504 10.931366 17.000000
      vertex 19.189018 10.821700 19.000000
    endloop
  endfacet
  facet normal 0.246757 -0.969077 0.000000
    outer loop
      vertex 18.652670 10.685129 17.000000
      vertex 19.189018 10.821700 17.000000
      vertex 19.189018 10.821700 19.000000
    endloop
  endfacet
  facet normal 0.294756 -0.955573 0.000000
    outer loop
      vertex 18.652670 10.685129 17.000000
      vertex 18.652670 10.685129 19.000000
      vertex 18.123798 10.521994 19.000000
    endloop
  endfacet
  facet normal 0.246757 -0.969077 0.000000
    outer loop
      vertex 18.652670 10.685129 17.000000
      vertex 19.189018 10.821700 19.000000
      vertex 18.652670 10.685129 19.000000
    endloop
  endfacet
  facet normal 0.294756 -0.955573 0.000000
    outer loop
      vertex 18.123798 10.521994 17.000000
      vertex 18.652670 10.685129 17.000000
      vertex 18.123798 10.521994 19.000000
    endloop
  endfacet
  facet normal 0.388436 -0.921476 0.000000
    outer loop
      vertex 17.603714 10.332699 17.000000
      vertex 17.603714 10.332699 19.000000
      vertex 17.093714 10.117715 19.000000
    endloop
  endfacet
  facet normal 0.342019 -0.939693 0.000000
    outer loop
      vertex 17.603714 10.332699 17.000000
      vertex 18.123798 10.521994 19.000000
      vertex 17.603714 10.332699 19.000000
    endloop
  endfacet
  facet normal 0.342019 -0.939693 0.000000
    outer loop
      vertex 17.603714 10.332699 17.000000
      vertex 18.123798 10.521994 17.000000
      vertex 18.123798 10.521994 19.000000
    endloop
  endfacet
  facet normal 0.388436 -0.921476 0.000000
    outer loop
      vertex 17.093714 10.117715 17.000000
      vertex 17.603714 10.332699 17.000000
      vertex 17.093714 10.117715 19.000000
    endloop
  endfacet
  facet normal 0.478253 -0.878222 0.000000
    outer loop
      vertex 16.595062 9.877577 17.000000
      vertex 16.595062 9.877577 19.000000
      vertex 16.108999 9.612882 19.000000
    endloop
  endfacet
  facet normal 0.433884 -0.900969 0.000000
    outer loop
      vertex 16.595062 9.877577 17.000000
      vertex 17.093714 10.117715 19.000000
      vertex 16.595062 9.877577 19.000000
    endloop
  endfacet
  facet normal 0.433884 -0.900969 0.000000
    outer loop
      vertex 16.595062 9.877577 17.000000
      vertex 17.093714 10.117715 17.000000
      vertex 17.093714 10.117715 19.000000
    endloop
  endfacet
  facet normal 0.478253 -0.878222 0.000000
    outer loop
      vertex 16.108999 9.612882 17.000000
      vertex 16.595062 9.877577 17.000000
      vertex 16.108999 9.612882 19.000000
    endloop
  endfacet
  facet normal 0.563319 -0.826240 0.000000
    outer loop
      vertex 15.636737 9.324287 17.000000
      vertex 15.636737 9.324287 19.000000
      vertex 15.179445 9.012512 19.000000
    endloop
  endfacet
  facet normal 0.521436 -0.853290 0.000000
    outer loop
      vertex 15.636737 9.324287 17.000000
      vertex 16.108999 9.612882 19.000000
      vertex 15.636737 9.324287 19.000000
    endloop
  endfacet
  facet normal 0.521436 -0.853290 0.000000
    outer loop
      vertex 15.636737 9.324287 17.000000
      vertex 16.108999 9.612882 17.000000
      vertex 16.108999 9.612882 19.000000
    endloop
  endfacet
  facet normal 0.603805 -0.797132 0.000000
    outer loop
      vertex 15.179445 9.012512 17.000000
      vertex 15.179445 9.012512 19.000000
      vertex 14.738263 8.678329 19.000000
    endloop
  endfacet
  facet normal 0.563319 -0.826240 0.000000
    outer loop
      vertex 15.179445 9.012512 17.000000
      vertex 15.636737 9.324287 17.000000
      vertex 15.179445 9.012512 19.000000
    endloop
  endfacet
  facet normal 0.603805 -0.797132 0.000000
    outer loop
      vertex 14.738263 8.678329 17.000000
      vertex 15.179445 9.012512 17.000000
      vertex 14.738263 8.678329 19.000000
    endloop
  endfacet
  facet normal 0.680173 -0.733052 0.000000
    outer loop
      vertex 14.314287 8.322572 17.000000
      vertex 14.314287 8.322572 19.000000
      vertex 13.908571 7.946122 19.000000
    endloop
  endfacet
  facet normal 0.642787 -0.766045 0.000000
    outer loop
      vertex 14.314287 8.322572 17.000000
      vertex 14.738263 8.678329 19.000000
      vertex 14.314287 8.322572 19.000000
    endloop
  endfacet
  facet normal 0.642787 -0.766045 0.000000
    outer loop
      vertex 14.314287 8.322572 17.000000
      vertex 14.738263 8.678329 17.000000
      vertex 14.738263 8.678329 19.000000
    endloop
  endfacet
  facet normal 0.680173 -0.733052 0.000000
    outer loop
      vertex 13.908571 7.946122 17.000000
      vertex 14.314287 8.322572 17.000000
      vertex 13.908571 7.946122 19.000000
    endloop
  endfacet
  facet normal 0.749781 -0.661686 0.000000
    outer loop
      vertex 13.522124 7.549917 17.000000
      vertex 13.522124 7.549917 19.000000
      vertex 13.155907 7.134943 19.000000
    endloop
  endfacet
  facet normal 0.715867 -0.698236 0.000000
    outer loop
      vertex 13.522124 7.549917 17.000000
      vertex 13.908571 7.946122 19.000000
      vertex 13.522124 7.549917 19.000000
    endloop
  endfacet
  facet normal 0.715867 -0.698236 0.000000
    outer loop
      vertex 13.522124 7.549917 17.000000
      vertex 13.908571 7.946122 17.000000
      vertex 13.908571 7.946122 19.000000
    endloop
  endfacet
  facet normal 0.781831 -0.623490 0.000000
    outer loop
      vertex 13.155907 7.134943 17.000000
      vertex 13.155907 7.134943 19.000000
      vertex 12.810829 6.702229 19.000000
    endloop
  endfacet
  facet normal 0.749781 -0.661686 0.000000
    outer loop
      vertex 13.155907 7.134943 17.000000
      vertex 13.522124 7.549917 17.000000
      vertex 13.155907 7.134943 19.000000
    endloop
  endfacet
  facet normal 0.811939 -0.583743 0.000000
    outer loop
      vertex 12.810829 6.702229 17.000000
      vertex 12.810829 6.702229 19.000000
      vertex 12.487750 6.252852 19.000000
    endloop
  endfacet
  facet normal 0.781831 -0.623490 0.000000
    outer loop
      vertex 12.810829 6.702229 17.000000
      vertex 13.155907 7.134943 17.000000
      vertex 12.810829 6.702229 19.000000
    endloop
  endfacet
  facet normal 0.811939 -0.583743 0.000000
    outer loop
      vertex 12.487750 6.252852 17.000000
      vertex 12.810829 6.702229 17.000000
      vertex 12.487750 6.252852 19.000000
    endloop
  endfacet
  facet normal 0.840025 -0.542547 0.000000
    outer loop
      vertex 12.187471 5.787931 17.000000
      vertex 12.487750 6.252852 19.000000
      vertex 12.187471 5.787931 19.000000
    endloop
  endfacet
  facet normal 0.840025 -0.542547 0.000000
    outer loop
      vertex 12.187471 5.787931 17.000000
      vertex 12.487750 6.252852 17.000000
      vertex 12.487750 6.252852 19.000000
    endloop
  endfacet
  facet normal 0.866026 -0.500000 0.000000
    outer loop
      vertex 11.910741 5.308619 17.000000
      vertex 12.187471 5.787931 17.000000
      vertex 12.187471 5.787931 19.000000
    endloop
  endfacet
  facet normal 0.866026 -0.500000 0.000000
    outer loop
      vertex 11.910741 5.308619 17.000000
      vertex 12.187471 5.787931 19.000000
      vertex 11.910741 5.308619 19.000000
    endloop
  endfacet
  facet normal 0.889872 -0.456211 0.000000
    outer loop
      vertex 11.658246 4.816110 17.000000
      vertex 11.910741 5.308619 17.000000
      vertex 11.910741 5.308619 19.000000
    endloop
  endfacet
  facet normal 0.911506 -0.411287 0.000000
    outer loop
      vertex 11.658246 4.816110 17.000000
      vertex 11.658246 4.816110 19.000000
      vertex 11.430614 4.311626 19.000000
    endloop
  endfacet
  facet normal 0.889872 -0.456211 0.000000
    outer loop
      vertex 11.658246 4.816110 17.000000
      vertex 11.910741 5.308619 19.000000
      vertex 11.658246 4.816110 19.000000
    endloop
  endfacet
  facet normal 0.911506 -0.411287 0.000000
    outer loop
      vertex 11.430614 4.311626 17.000000
      vertex 11.658246 4.816110 17.000000
      vertex 11.430614 4.311626 19.000000
    endloop
  endfacet
  facet normal 0.930873 -0.365342 0.000000
    outer loop
      vertex 11.228412 3.796424 17.000000
      vertex 11.430614 4.311626 17.000000
      vertex 11.430614 4.311626 19.000000
    endloop
  endfacet
  facet normal 0.947928 -0.318486 0.000000
    outer loop
      vertex 11.228412 3.796424 17.000000
      vertex 11.228412 3.796424 19.000000
      vertex 11.052142 3.271782 19.000000
    endloop
  endfacet
  facet normal 0.930873 -0.365342 0.000000
    outer loop
      vertex 11.228412 3.796424 17.000000
      vertex 11.430614 4.311626 19.000000
      vertex 11.228412 3.796424 19.000000
    endloop
  endfacet
  facet normal 0.947928 -0.318486 0.000000
    outer loop
      vertex 11.052142 3.271782 17.000000
      vertex 11.228412 3.796424 17.000000
      vertex 11.052142 3.271782 19.000000
    endloop
  endfacet
  facet normal 0.962624 -0.270842 0.000000
    outer loop
      vertex 10.902242 2.739007 17.000000
      vertex 11.052142 3.271782 17.000000
      vertex 11.052142 3.271782 19.000000
    endloop
  endfacet
  facet normal 0.974928 -0.222521 0.000000
    outer loop
      vertex 10.902242 2.739007 17.000000
      vertex 10.902242 2.739007 19.000000
      vertex 10.779085 2.199422 19.000000
    endloop
  endfacet
  facet normal 0.962624 -0.270842 0.000000
    outer loop
      vertex 10.902242 2.739007 17.000000
      vertex 11.052142 3.271782 19.000000
      vertex 10.902242 2.739007 19.000000
    endloop
  endfacet
  facet normal 0.984808 -0.173648 0.000000
    outer loop
      vertex 10.779085 2.199422 17.000000
      vertex 10.779085 2.199422 19.000000
      vertex 10.682978 1.654369 19.000000
    endloop
  endfacet
  facet normal 0.974928 -0.222521 0.000000
    outer loop
      vertex 10.779085 2.199422 17.000000
      vertex 10.902242 2.739007 17.000000
      vertex 10.779085 2.199422 19.000000
    endloop
  endfacet
  facet normal 0.984808 -0.173648 0.000000
    outer loop
      vertex 10.682978 1.654369 17.000000
      vertex 10.779085 2.199422 17.000000
      vertex 10.682978 1.654369 19.000000
    endloop
  endfacet
  facet normal 0.997204 -0.074731 0.000000
    outer loop
      vertex 10.614159 1.105203 17.000000
      vertex 10.614159 1.105203 19.000000
      vertex 10.572798 0.553289 19.000000
    endloop
  endfacet
  facet normal 0.992239 -0.124343 0.000000
    outer loop
      vertex 10.614159 1.105203 17.000000
      vertex 10.682978 1.654369 19.000000
      vertex 10.614159 1.105203 19.000000
    endloop
  endfacet
  facet normal 0.992239 -0.124343 0.000000
    outer loop
      vertex 10.614159 1.105203 17.000000
      vertex 10.682978 1.654369 17.000000
      vertex 10.682978 1.654369 19.000000
    endloop
  endfacet
  facet normal 0.997204 -0.074731 0.000000
    outer loop
      vertex 10.572798 0.553289 17.000000
      vertex 10.614159 1.105203 17.000000
      vertex 10.572798 0.553289 19.000000
    endloop
  endfacet
  facet normal 0.999689 -0.024930 0.000000
    outer loop
      vertex 10.559000 0.000000 17.000000
      vertex 10.572798 0.553289 17.000000
      vertex 10.572798 0.553289 19.000000
    endloop
  endfacet
  facet normal 0.999689 0.024930 -0.000000
    outer loop
      vertex 10.559000 0.000000 17.000000
      vertex 10.559000 0.000000 19.000000
      vertex 10.572798 -0.553289 19.000000
    endloop
  endfacet
  facet normal 0.999689 -0.024930 0.000000
    outer loop
      vertex 10.559000 0.000000 17.000000
      vertex 10.572798 0.553289 19.000000
      vertex 10.559000 0.000000 19.000000
    endloop
  endfacet
  facet normal 0.999689 0.024930 -0.000000
    outer loop
      vertex 10.572798 -0.553289 17.000000
      vertex 10.559000 0.000000 17.000000
      vertex 10.572798 -0.553289 19.000000
    endloop
  endfacet
  facet normal 0.997204 0.074731 0.000000
    outer loop
      vertex 10.614159 -1.105203 17.000000
      vertex 10.572798 -0.553289 17.000000
      vertex 10.572798 -0.553289 19.000000
    endloop
  endfacet
  facet normal 0.997204 0.074731 -0.000000
    outer loop
      vertex 10.614159 -1.105203 17.000000
      vertex 10.572798 -0.553289 19.000000
      vertex 10.614159 -1.105203 19.000000
    endloop
  endfacet
  facet normal 0.992239 0.124343 0.000000
    outer loop
      vertex 10.682978 -1.654369 17.000000
      vertex 10.614159 -1.105203 17.000000
      vertex 10.614159 -1.105203 19.000000
    endloop
  endfacet
  facet normal 0.992239 0.124343 -0.000000
    outer loop
      vertex 10.682978 -1.654369 17.000000
      vertex 10.614159 -1.105203 19.000000
      vertex 10.682978 -1.654369 19.000000
    endloop
  endfacet
  facet normal 0.984808 0.173648 0.000000
    outer loop
      vertex 10.779085 -2.199422 17.000000
      vertex 10.682978 -1.654369 17.000000
      vertex 10.682978 -1.654369 19.000000
    endloop
  endfacet
  facet normal 0.974928 0.222521 -0.000000
    outer loop
      vertex 10.779085 -2.199422 17.000000
      vertex 10.779085 -2.199422 19.000000
      vertex 10.902242 -2.739007 19.000000
    endloop
  endfacet
  facet normal 0.984808 0.173648 -0.000000
    outer loop
      vertex 10.779085 -2.199422 17.000000
      vertex 10.682978 -1.654369 19.000000
      vertex 10.779085 -2.199422 19.000000
    endloop
  endfacet
  facet normal 0.974928 0.222521 -0.000000
    outer loop
      vertex 10.902242 -2.739007 17.000000
      vertex 10.779085 -2.199422 17.000000
      vertex 10.902242 -2.739007 19.000000
    endloop
  endfacet
  facet normal 0.962624 0.270842 0.000000
    outer loop
      vertex 11.052142 -3.271782 17.000000
      vertex 10.902242 -2.739007 17.000000
      vertex 10.902242 -2.739007 19.000000
    endloop
  endfacet
  facet normal 0.962624 0.270842 -0.000000
    outer loop
      vertex 11.052142 -3.271782 17.000000
      vertex 10.902242 -2.739007 19.000000
      vertex 11.052142 -3.271782 19.000000
    endloop
  endfacet
  facet normal 0.947928 0.318486 0.000000
    outer loop
      vertex 11.228412 -3.796424 17.000000
      vertex 11.052142 -3.271782 17.000000
      vertex 11.052142 -3.271782 19.000000
    endloop
  endfacet
  facet normal 0.947928 0.318486 -0.000000
    outer loop
      vertex 11.228412 -3.796424 17.000000
      vertex 11.052142 -3.271782 19.000000
      vertex 11.228412 -3.796424 19.000000
    endloop
  endfacet
  facet normal 0.930873 0.365342 0.000000
    outer loop
      vertex 11.430614 -4.311626 17.000000
      vertex 11.228412 -3.796424 17.000000
      vertex 11.228412 -3.796424 19.000000
    endloop
  endfacet
  facet normal 0.930873 0.365342 -0.000000
    outer loop
      vertex 11.430614 -4.311626 17.000000
      vertex 11.228412 -3.796424 19.000000
      vertex 11.430614 -4.311626 19.000000
    endloop
  endfacet
  facet normal 0.911506 0.411287 0.000000
    outer loop
      vertex 11.658246 -4.816110 17.000000
      vertex 11.430614 -4.311626 17.000000
      vertex 11.430614 -4.311626 19.000000
    endloop
  endfacet
  facet normal 0.911506 0.411287 -0.000000
    outer loop
      vertex 11.658246 -4.816110 17.000000
      vertex 11.430614 -4.311626 19.000000
      vertex 11.658246 -4.816110 19.000000
    endloop
  endfacet
  facet normal 0.889872 0.456211 0.000000
    outer loop
      vertex 11.910741 -5.308619 17.000000
      vertex 11.658246 -4.816110 17.000000
      vertex 11.658246 -4.816110 19.000000
    endloop
  endfacet
  facet normal 0.889872 0.456211 -0.000000
    outer loop
      vertex 11.910741 -5.308619 17.000000
      vertex 11.658246 -4.816110 19.000000
      vertex 11.910741 -5.308619 19.000000
    endloop
  endfacet
  facet normal 0.866026 0.500000 0.000000
    outer loop
      vertex 12.187471 -5.787931 17.000000
      vertex 11.910741 -5.308619 17.000000
      vertex 11.910741 -5.308619 19.000000
    endloop
  endfacet
  facet normal 0.866026 0.500000 -0.000000
    outer loop
      vertex 12.187471 -5.787931 17.000000
      vertex 11.910741 -5.308619 19.000000
      vertex 12.187471 -5.787931 19.000000
    endloop
  endfacet
  facet normal 0.840025 0.542547 0.000000
    outer loop
      vertex 12.487750 -6.252852 17.000000
      vertex 12.187471 -5.787931 17.000000
      vertex 12.187471 -5.787931 19.000000
    endloop
  endfacet
  facet normal 0.840025 0.542547 -0.000000
    outer loop
      vertex 12.487750 -6.252852 17.000000
      vertex 12.187471 -5.787931 19.000000
      vertex 12.487750 -6.252852 19.000000
    endloop
  endfacet
  facet normal 0.811939 0.583743 0.000000
    outer loop
      vertex 12.810829 -6.702229 17.000000
      vertex 12.487750 -6.252852 17.000000
      vertex 12.487750 -6.252852 19.000000
    endloop
  endfacet
  facet normal 0.811939 0.583743 -0.000000
    outer loop
      vertex 12.810829 -6.702229 17.000000
      vertex 12.487750 -6.252852 19.000000
      vertex 12.810829 -6.702229 19.000000
    endloop
  endfacet
  facet normal 0.781831 0.623490 0.000000
    outer loop
      vertex 13.155907 -7.134943 17.000000
      vertex 12.810829 -6.702229 17.000000
      vertex 12.810829 -6.702229 19.000000
    endloop
  endfacet
  facet normal 0.781831 0.623490 -0.000000
    outer loop
      vertex 13.155907 -7.134943 17.000000
      vertex 12.810829 -6.702229 19.000000
      vertex 13.155907 -7.134943 19.000000
    endloop
  endfacet
  facet normal 0.749781 0.661686 0.000000
    outer loop
      vertex 13.522124 -7.549917 17.000000
      vertex 13.155907 -7.134943 17.000000
      vertex 13.155907 -7.134943 19.000000
    endloop
  endfacet
  facet normal 0.749781 0.661686 -0.000000
    outer loop
      vertex 13.522124 -7.549917 17.000000
      vertex 13.155907 -7.134943 19.000000
      vertex 13.522124 -7.549917 19.000000
    endloop
  endfacet
  facet normal 0.715867 0.698236 0.000000
    outer loop
      vertex 13.908571 -7.946122 17.000000
      vertex 13.522124 -7.549917 17.000000
      vertex 13.522124 -7.549917 19.000000
    endloop
  endfacet
  facet normal 0.680173 0.733052 -0.000000
    outer loop
      vertex 13.908571 -7.946122 17.000000
      vertex 13.908571 -7.946122 19.000000
      vertex 14.314287 -8.322572 19.000000
    endloop
  endfacet
  facet normal 0.715867 0.698236 -0.000000
    outer loop
      vertex 13.908571 -7.946122 17.000000
      vertex 13.522124 -7.549917 19.000000
      vertex 13.908571 -7.946122 19.000000
    endloop
  endfacet
  facet normal 0.680173 0.733052 -0.000000
    outer loop
      vertex 14.314287 -8.322572 17.000000
      vertex 13.908571 -7.946122 17.000000
      vertex 14.314287 -8.322572 19.000000
    endloop
  endfacet
  facet normal 0.603805 0.797132 -0.000000
    outer loop
      vertex 14.738263 -8.678329 17.000000
      vertex 14.738263 -8.678329 19.000000
      vertex 15.179445 -9.012512 19.000000
    endloop
  endfacet
  facet normal 0.642787 0.766045 -0.000000
    outer loop
      vertex 14.738263 -8.678329 17.000000
      vertex 14.314287 -8.322572 19.000000
      vertex 14.738263 -8.678329 19.000000
    endloop
  endfacet
  facet normal 0.642787 0.766045 0.000000
    outer loop
      vertex 14.738263 -8.678329 17.000000
      vertex 14.314287 -8.322572 17.000000
      vertex 14.314287 -8.322572 19.000000
    endloop
  endfacet
  facet normal 0.603805 0.797132 -0.000000
    outer loop
      vertex 15.179445 -9.012512 17.000000
      vertex 14.738263 -8.678329 17.000000
      vertex 15.179445 -9.012512 19.000000
    endloop
  endfacet
  facet normal 0.521436 0.853290 -0.000000
    outer loop
      vertex 15.636737 -9.324287 17.000000
      vertex 15.636737 -9.324287 19.000000
      vertex 16.108999 -9.612882 19.000000
    endloop
  endfacet
  facet normal 0.563319 0.826240 -0.000000
    outer loop
      vertex 15.636737 -9.324287 17.000000
      vertex 15.179445 -9.012512 19.000000
      vertex 15.636737 -9.324287 19.000000
    endloop
  endfacet
  facet normal 0.563319 0.826240 0.000000
    outer loop
      vertex 15.636737 -9.324287 17.000000
      vertex 15.179445 -9.012512 17.000000
      vertex 15.179445 -9.012512 19.000000
    endloop
  endfacet
  facet normal 0.521436 0.853290 -0.000000
    outer loop
      vertex 16.108999 -9.612882 17.000000
      vertex 15.636737 -9.324287 17.000000
      vertex 16.108999 -9.612882 19.000000
    endloop
  endfacet
  facet normal 0.433884 0.900969 -0.000000
    outer loop
      vertex 16.595062 -9.877577 17.000000
      vertex 16.595062 -9.877577 19.000000
      vertex 17.093714 -10.117715 19.000000
    endloop
  endfacet
  facet normal 0.478253 0.878222 -0.000000
    outer loop
      vertex 16.595062 -9.877577 17.000000
      vertex 16.108999 -9.612882 19.000000
      vertex 16.595062 -9.877577 19.000000
    endloop
  endfacet
  facet normal 0.478253 0.878222 0.000000
    outer loop
      vertex 16.595062 -9.877577 17.000000
      vertex 16.108999 -9.612882 17.000000
      vertex 16.108999 -9.612882 19.000000
    endloop
  endfacet
  facet normal 0.433884 0.900969 -0.000000
    outer loop
      vertex 17.093714 -10.117715 17.000000
      vertex 16.595062 -9.877577 17.000000
      vertex 17.093714 -10.117715 19.000000
    endloop
  endfacet
  facet normal 0.388436 0.921476 0.000000
    outer loop
      vertex 17.603714 -10.332699 17.000000
      vertex 17.093714 -10.117715 17.000000
      vertex 17.093714 -10.117715 19.000000
    endloop
  endfacet
  facet normal 0.388436 0.921476 -0.000000
    outer loop
      vertex 17.603714 -10.332699 17.000000
      vertex 17.093714 -10.117715 19.000000
      vertex 17.603714 -10.332699 19.000000
    endloop
  endfacet
  facet normal 0.342019 0.939693 0.000000
    outer loop
      vertex 18.123798 -10.521994 17.000000
      vertex 17.603714 -10.332699 17.000000
      vertex 17.603714 -10.332699 19.000000
    endloop
  endfacet
  facet normal 0.294756 0.955573 -0.000000
    outer loop
      vertex 18.123798 -10.521994 17.000000
      vertex 18.123798 -10.521994 19.000000
      vertex 18.652670 -10.685129 19.000000
    endloop
  endfacet
  facet normal 0.342019 0.939693 -0.000000
    outer loop
      vertex 18.123798 -10.521994 17.000000
      vertex 17.603714 -10.332699 19.000000
      vertex 18.123798 -10.521994 19.000000
    endloop
  endfacet
  facet normal 0.294756 0.955573 -0.000000
    outer loop
      vertex 18.652670 -10.685129 17.000000
      vertex 18.123798 -10.521994 17.000000
      vertex 18.652670 -10.685129 19.000000
    endloop
  endfacet
  facet normal 0.246757 0.969077 0.000000
    outer loop
      vertex 19.189018 -10.821700 17.000000
      vertex 18.652670 -10.685129 17.000000
      vertex 18.652670 -10.685129 19.000000
    endloop
  endfacet
  facet normal 0.246757 0.969077 -0.000000
    outer loop
      vertex 19.189018 -10.821700 17.000000
      vertex 18.652670 -10.685129 19.000000
      vertex 19.189018 -10.821700 19.000000
    endloop
  endfacet
  facet normal 0.198146 0.980173 0.000000
    outer loop
      vertex 19.731504 -10.931366 17.000000
      vertex 19.189018 -10.821700 17.000000
      vertex 19.189018 -10.821700 19.000000
    endloop
  endfacet
  facet normal 0.198146 0.980173 -0.000000
    outer loop
      vertex 19.731504 -10.931366 17.000000
      vertex 19.189018 -10.821700 19.000000
      vertex 19.731504 -10.931366 19.000000
    endloop
  endfacet
  facet normal 0.149042 0.988831 0.000000
    outer loop
      vertex 20.278786 -11.013855 17.000000
      vertex 19.731504 -10.931366 17.000000
      vertex 19.731504 -10.931366 19.000000
    endloop
  endfacet
  facet normal 0.099568 0.995031 -0.000000
    outer loop
      vertex 20.278786 -11.013855 17.000000
      vertex 20.278786 -11.013855 19.000000
      vertex 20.829496 -11.068962 19.000000
    endloop
  endfacet
  facet normal 0.149042 0.988831 -0.000000
    outer loop
      vertex 20.278786 -11.013855 17.000000
      vertex 19.731504 -10.931366 19.000000
      vertex 20.278786 -11.013855 19.000000
    endloop
  endfacet
  facet normal 0.099568 0.995031 -0.000000
    outer loop
      vertex 20.829496 -11.068962 17.000000
      vertex 20.278786 -11.013855 17.000000
      vertex 20.829496 -11.068962 19.000000
    endloop
  endfacet
  facet normal 0.049846 0.998757 0.000000
    outer loop
      vertex 21.382269 -11.096550 17.000000
      vertex 20.829496 -11.068962 17.000000
      vertex 20.829496 -11.068962 19.000000
    endloop
  endfacet
  facet normal 0.000000 1.000000 0.000000
    outer loop
      vertex 21.382269 -11.096550 17.000000
      vertex 21.382269 -11.096550 19.000000
      vertex 21.935730 -11.096550 19.000000
    endloop
  endfacet
  facet normal 0.049846 0.998757 -0.000000
    outer loop
      vertex 21.382269 -11.096550 17.000000
      vertex 20.829496 -11.068962 19.000000
      vertex 21.382269 -11.096550 19.000000
    endloop
  endfacet
  facet normal 0.000000 1.000000 -0.000000
    outer loop
      vertex 21.935730 -11.096550 17.000000
      vertex 21.382269 -11.096550 17.000000
      vertex 21.935730 -11.096550 19.000000
    endloop
  endfacet
  facet normal -0.049846 0.998757 0.000000
    outer loop
      vertex 22.488504 -11.068962 17.000000
      vertex 21.935730 -11.096550 17.000000
      vertex 21.935730 -11.096550 19.000000
    endloop
  endfacet
  facet normal -0.049846 0.998757 0.000000
    outer loop
      vertex 22.488504 -11.068962 17.000000
      vertex 21.935730 -11.096550 19.000000
      vertex 22.488504 -11.068962 19.000000
    endloop
  endfacet
  facet normal -0.099568 0.995031 0.000000
    outer loop
      vertex 23.039215 -11.013855 17.000000
      vertex 22.488504 -11.068962 17.000000
      vertex 22.488504 -11.068962 19.000000
    endloop
  endfacet
  facet normal -0.099568 0.995031 0.000000
    outer loop
      vertex 23.039215 -11.013855 17.000000
      vertex 22.488504 -11.068962 19.000000
      vertex 23.039215 -11.013855 19.000000
    endloop
  endfacet
  facet normal -0.149042 0.988831 0.000000
    outer loop
      vertex 23.586494 -10.931366 17.000000
      vertex 23.039215 -11.013855 17.000000
      vertex 23.039215 -11.013855 19.000000
    endloop
  endfacet
  facet normal -0.198145 0.980173 0.000000
    outer loop
      vertex 23.586494 -10.931366 17.000000
      vertex 23.586494 -10.931366 19.000000
      vertex 24.128983 -10.821700 19.000000
    endloop
  endfacet
  facet normal -0.149042 0.988831 0.000000
    outer loop
      vertex 23.586494 -10.931366 17.000000
      vertex 23.039215 -11.013855 19.000000
      vertex 23.586494 -10.931366 19.000000
    endloop
  endfacet
  facet normal -0.198145 0.980173 0.000000
    outer loop
      vertex 24.128983 -10.821700 17.000000
      vertex 23.586494 -10.931366 17.000000
      vertex 24.128983 -10.821700 19.000000
    endloop
  endfacet
  facet normal -0.246758 0.969077 0.000000
    outer loop
      vertex 24.665329 -10.685129 17.000000
      vertex 24.128983 -10.821700 17.000000
      vertex 24.128983 -10.821700 19.000000
    endloop
  endfacet
  facet normal -0.294755 0.955573 0.000000
    outer loop
      vertex 24.665329 -10.685129 17.000000
      vertex 24.665329 -10.685129 19.000000
      vertex 25.194202 -10.521994 19.000000
    endloop
  endfacet
  facet normal -0.246758 0.969077 0.000000
    outer loop
      vertex 24.665329 -10.685129 17.000000
      vertex 24.128983 -10.821700 19.000000
      vertex 24.665329 -10.685129 19.000000
    endloop
  endfacet
  facet normal -0.294755 0.955573 0.000000
    outer loop
      vertex 25.194202 -10.521994 17.000000
      vertex 24.665329 -10.685129 17.000000
      vertex 25.194202 -10.521994 19.000000
    endloop
  endfacet
  facet normal -0.388435 0.921476 0.000000
    outer loop
      vertex 25.714285 -10.332699 17.000000
      vertex 25.714285 -10.332699 19.000000
      vertex 26.224287 -10.117715 19.000000
    endloop
  endfacet
  facet normal -0.342021 0.939692 0.000000
    outer loop
      vertex 25.714285 -10.332699 17.000000
      vertex 25.194202 -10.521994 19.000000
      vertex 25.714285 -10.332699 19.000000
    endloop
  endfacet
  facet normal -0.342021 0.939692 0.000000
    outer loop
      vertex 25.714285 -10.332699 17.000000
      vertex 25.194202 -10.521994 17.000000
      vertex 25.194202 -10.521994 19.000000
    endloop
  endfacet
  facet normal -0.388435 0.921476 0.000000
    outer loop
      vertex 26.224287 -10.117715 17.000000
      vertex 25.714285 -10.332699 17.000000
      vertex 26.224287 -10.117715 19.000000
    endloop
  endfacet
  facet normal -0.478254 0.878221 0.000000
    outer loop
      vertex 26.722939 -9.877577 17.000000
      vertex 26.722939 -9.877577 19.000000
      vertex 27.209000 -9.612882 19.000000
    endloop
  endfacet
  facet normal -0.433884 0.900969 0.000000
    outer loop
      vertex 26.722939 -9.877577 17.000000
      vertex 26.224287 -10.117715 19.000000
      vertex 26.722939 -9.877577 19.000000
    endloop
  endfacet
  facet normal -0.433884 0.900969 0.000000
    outer loop
      vertex 26.722939 -9.877577 17.000000
      vertex 26.224287 -10.117715 17.000000
      vertex 26.224287 -10.117715 19.000000
    endloop
  endfacet
  facet normal -0.478254 0.878221 0.000000
    outer loop
      vertex 27.209000 -9.612882 17.000000
      vertex 26.722939 -9.877577 17.000000
      vertex 27.209000 -9.612882 19.000000
    endloop
  endfacet
  facet normal -0.521435 0.853291 0.000000
    outer loop
      vertex 27.681263 -9.324287 17.000000
      vertex 27.209000 -9.612882 19.000000
      vertex 27.681263 -9.324287 19.000000
    endloop
  endfacet
  facet normal -0.521435 0.853291 0.000000
    outer loop
      vertex 27.681263 -9.324287 17.000000
      vertex 27.209000 -9.612882 17.000000
      vertex 27.209000 -9.612882 19.000000
    endloop
  endfacet
  facet normal -0.563318 0.826240 0.000000
    outer loop
      vertex 28.138556 -9.012512 17.000000
      vertex 27.681263 -9.324287 19.000000
      vertex 28.138556 -9.012512 19.000000
    endloop
  endfacet
  facet normal -0.563318 0.826240 0.000000
    outer loop
      vertex 28.138556 -9.012512 17.000000
      vertex 27.681263 -9.324287 17.000000
      vertex 27.681263 -9.324287 19.000000
    endloop
  endfacet
  facet normal -0.603805 0.797132 0.000000
    outer loop
      vertex 28.579737 -8.678329 17.000000
      vertex 28.138556 -9.012512 19.000000
      vertex 28.579737 -8.678329 19.000000
    endloop
  endfacet
  facet normal -0.603805 0.797132 0.000000
    outer loop
      vertex 28.579737 -8.678329 17.000000
      vertex 28.138556 -9.012512 17.000000
      vertex 28.138556 -9.012512 19.000000
    endloop
  endfacet
  facet normal -0.642786 0.766045 0.000000
    outer loop
      vertex 29.003714 -8.322572 17.000000
      vertex 28.579737 -8.678329 19.000000
      vertex 29.003714 -8.322572 19.000000
    endloop
  endfacet
  facet normal -0.642786 0.766045 0.000000
    outer loop
      vertex 29.003714 -8.322572 17.000000
      vertex 28.579737 -8.678329 17.000000
      vertex 28.579737 -8.678329 19.000000
    endloop
  endfacet
  facet normal -0.680173 0.733052 0.000000
    outer loop
      vertex 29.409430 -7.946122 17.000000
      vertex 29.003714 -8.322572 19.000000
      vertex 29.409430 -7.946122 19.000000
    endloop
  endfacet
  facet normal -0.680173 0.733052 0.000000
    outer loop
      vertex 29.409430 -7.946122 17.000000
      vertex 29.003714 -8.322572 17.000000
      vertex 29.003714 -8.322572 19.000000
    endloop
  endfacet
  facet normal -0.715868 0.698236 0.000000
    outer loop
      vertex 29.795876 -7.549917 17.000000
      vertex 29.409430 -7.946122 19.000000
      vertex 29.795876 -7.549917 19.000000
    endloop
  endfacet
  facet normal -0.715868 0.698236 0.000000
    outer loop
      vertex 29.795876 -7.549917 17.000000
      vertex 29.409430 -7.946122 17.000000
      vertex 29.409430 -7.946122 19.000000
    endloop
  endfacet
  facet normal -0.749780 0.661687 0.000000
    outer loop
      vertex 30.162094 -7.134943 17.000000
      vertex 29.795876 -7.549917 19.000000
      vertex 30.162094 -7.134943 19.000000
    endloop
  endfacet
  facet normal -0.749780 0.661687 0.000000
    outer loop
      vertex 30.162094 -7.134943 17.000000
      vertex 29.795876 -7.549917 17.000000
      vertex 29.795876 -7.549917 19.000000
    endloop
  endfacet
  facet normal -0.781831 0.623490 0.000000
    outer loop
      vertex 30.507172 -6.702229 17.000000
      vertex 30.162094 -7.134943 17.000000
      vertex 30.162094 -7.134943 19.000000
    endloop
  endfacet
  facet normal -0.811939 0.583742 0.000000
    outer loop
      vertex 30.507172 -6.702229 17.000000
      vertex 30.507172 -6.702229 19.000000
      vertex 30.830250 -6.252852 19.000000
    endloop
  endfacet
  facet normal -0.781831 0.623490 0.000000
    outer loop
      vertex 30.507172 -6.702229 17.000000
      vertex 30.162094 -7.134943 19.000000
      vertex 30.507172 -6.702229 19.000000
    endloop
  endfacet
  facet normal -0.811939 0.583742 0.000000
    outer loop
      vertex 30.830250 -6.252852 17.000000
      vertex 30.507172 -6.702229 17.000000
      vertex 30.830250 -6.252852 19.000000
    endloop
  endfacet
  facet normal -0.840025 0.542548 0.000000
    outer loop
      vertex 31.130529 -5.787931 17.000000
      vertex 30.830250 -6.252852 17.000000
      vertex 30.830250 -6.252852 19.000000
    endloop
  endfacet
  facet normal -0.840025 0.542548 0.000000
    outer loop
      vertex 31.130529 -5.787931 17.000000
      vertex 30.830250 -6.252852 19.000000
      vertex 31.130529 -5.787931 19.000000
    endloop
  endfacet
  facet normal -0.866026 0.499998 0.000000
    outer loop
      vertex 31.407259 -5.308619 17.000000
      vertex 31.130529 -5.787931 17.000000
      vertex 31.130529 -5.787931 19.000000
    endloop
  endfacet
  facet normal -0.889872 0.456211 0.000000
    outer loop
      vertex 31.407259 -5.308619 17.000000
      vertex 31.407259 -5.308619 19.000000
      vertex 31.659754 -4.816110 19.000000
    endloop
  endfacet
  facet normal -0.866026 0.499998 0.000000
    outer loop
      vertex 31.407259 -5.308619 17.000000
      vertex 31.130529 -5.787931 19.000000
      vertex 31.407259 -5.308619 19.000000
    endloop
  endfacet
  facet normal -0.889872 0.456211 0.000000
    outer loop
      vertex 31.659754 -4.816110 17.000000
      vertex 31.407259 -5.308619 17.000000
      vertex 31.659754 -4.816110 19.000000
    endloop
  endfacet
  facet normal -0.911505 0.411289 0.000000
    outer loop
      vertex 31.887386 -4.311626 17.000000
      vertex 31.659754 -4.816110 17.000000
      vertex 31.659754 -4.816110 19.000000
    endloop
  endfacet
  facet normal -0.930874 0.365340 0.000000
    outer loop
      vertex 31.887386 -4.311626 17.000000
      vertex 31.887386 -4.311626 19.000000
      vertex 32.089588 -3.796424 19.000000
    endloop
  endfacet
  facet normal -0.911505 0.411289 0.000000
    outer loop
      vertex 31.887386 -4.311626 17.000000
      vertex 31.659754 -4.816110 19.000000
      vertex 31.887386 -4.311626 19.000000
    endloop
  endfacet
  facet normal -0.930874 0.365340 0.000000
    outer loop
      vertex 32.089588 -3.796424 17.000000
      vertex 31.887386 -4.311626 17.000000
      vertex 32.089588 -3.796424 19.000000
    endloop
  endfacet
  facet normal -0.947928 0.318486 0.000000
    outer loop
      vertex 32.265858 -3.271782 17.000000
      vertex 32.089588 -3.796424 17.000000
      vertex 32.089588 -3.796424 19.000000
    endloop
  endfacet
  facet normal -0.947928 0.318486 0.000000
    outer loop
      vertex 32.265858 -3.271782 17.000000
      vertex 32.089588 -3.796424 19.000000
      vertex 32.265858 -3.271782 19.000000
    endloop
  endfacet
  facet normal -0.974928 0.222522 0.000000
    outer loop
      vertex 32.415756 -2.739007 17.000000
      vertex 32.415756 -2.739007 19.000000
      vertex 32.538914 -2.199422 19.000000
    endloop
  endfacet
  facet normal -0.962625 0.270838 0.000000
    outer loop
      vertex 32.415756 -2.739007 17.000000
      vertex 32.265858 -3.271782 19.000000
      vertex 32.415756 -2.739007 19.000000
    endloop
  endfacet
  facet normal -0.962625 0.270838 0.000000
    outer loop
      vertex 32.415756 -2.739007 17.000000
      vertex 32.265858 -3.271782 17.000000
      vertex 32.265858 -3.271782 19.000000
    endloop
  endfacet
  facet normal -0.974928 0.222522 0.000000
    outer loop
      vertex 32.538914 -2.199422 17.000000
      vertex 32.415756 -2.739007 17.000000
      vertex 32.538914 -2.199422 19.000000
    endloop
  endfacet
  facet normal -0.984808 0.173648 0.000000
    outer loop
      vertex 32.635021 -1.654369 17.000000
      vertex 32.538914 -2.199422 19.000000
      vertex 32.635021 -1.654369 19.000000
    endloop
  endfacet
  facet normal -0.984808 0.173648 0.000000
    outer loop
      vertex 32.635021 -1.654369 17.000000
      vertex 32.538914 -2.199422 17.000000
      vertex 32.538914 -2.199422 19.000000
    endloop
  endfacet
  facet normal -0.992239 0.124346 0.000000
    outer loop
      vertex 32.703842 -1.105203 17.000000
      vertex 32.635021 -1.654369 19.000000
      vertex 32.703842 -1.105203 19.000000
    endloop
  endfacet
  facet normal -0.992239 0.124346 0.000000
    outer loop
      vertex 32.703842 -1.105203 17.000000
      vertex 32.635021 -1.654369 17.000000
      vertex 32.635021 -1.654369 19.000000
    endloop
  endfacet
  facet normal -0.997204 0.074728 0.000000
    outer loop
      vertex 32.745201 -0.553289 17.000000
      vertex 32.703842 -1.105203 19.000000
      vertex 32.745201 -0.553289 19.000000
    endloop
  endfacet
  facet normal -0.997204 0.074728 0.000000
    outer loop
      vertex 32.745201 -0.553289 17.000000
      vertex 32.703842 -1.105203 17.000000
      vertex 32.703842 -1.105203 19.000000
    endloop
  endfacet
  facet normal -0.999689 0.024930 0.000000
    outer loop
      vertex 32.758999 0.000000 17.000000
      vertex 32.745201 -0.553289 19.000000
      vertex 32.758999 0.000000 19.000000
    endloop
  endfacet
  facet normal -0.999689 0.024930 0.000000
    outer loop
      vertex 32.758999 0.000000 17.000000
      vertex 32.745201 -0.553289 17.000000
      vertex 32.745201 -0.553289 19.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -29.796875 -7.549917 17.000000
      vertex -29.410429 -7.946122 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -29.410429 -7.946122 17.000000
      vertex -29.004713 -8.322572 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -30.163094 -7.134943 17.000000
      vertex -29.796875 -7.549917 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -29.004713 -8.322572 17.000000
      vertex -28.580736 -8.678329 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -30.508171 -6.702229 17.000000
      vertex -30.163094 -7.134943 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -28.580736 -8.678329 17.000000
      vertex -28.139555 -9.012512 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -30.831251 -6.252852 17.000000
      vertex -30.508171 -6.702229 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -28.139555 -9.012512 17.000000
      vertex -27.682264 -9.324287 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -31.131529 -5.787931 17.000000
      vertex -30.831251 -6.252852 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -27.682264 -9.324287 17.000000
      vertex -27.209999 -9.612882 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -31.408260 -5.308619 17.000000
      vertex -31.131529 -5.787931 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -27.209999 -9.612882 17.000000
      vertex -26.723938 -9.877577 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -31.660755 -4.816110 17.000000
      vertex -31.408260 -5.308619 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -26.723938 -9.877577 17.000000
      vertex -26.225286 -10.117715 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -31.888386 -4.311626 17.000000
      vertex -31.660755 -4.816110 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -26.225286 -10.117715 17.000000
      vertex -25.715286 -10.332699 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -32.090588 -3.796424 17.000000
      vertex -31.888386 -4.311626 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -25.715286 -10.332699 17.000000
      vertex -25.195202 -10.521994 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -32.266857 -3.271782 17.000000
      vertex -32.090588 -3.796424 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -25.195202 -10.521994 17.000000
      vertex -24.666328 -10.685129 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -32.416759 -2.739007 17.000000
      vertex -32.266857 -3.271782 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -24.666328 -10.685129 17.000000
      vertex -24.129982 -10.821700 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -32.539913 -2.199422 17.000000
      vertex -32.416759 -2.739007 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -24.129982 -10.821700 17.000000
      vertex -23.587494 -10.931366 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -32.636021 -1.654369 17.000000
      vertex -32.539913 -2.199422 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -23.587494 -10.931366 17.000000
      vertex -23.040215 -11.013855 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -32.704842 -1.105203 17.000000
      vertex -32.636021 -1.654369 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -23.040215 -11.013855 17.000000
      vertex -22.489504 -11.068962 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -32.746201 -0.553289 17.000000
      vertex -32.704842 -1.105203 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -22.489504 -11.068962 17.000000
      vertex -21.936731 -11.096550 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -32.759998 0.000000 17.000000
      vertex -32.746201 -0.553289 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -21.936731 -11.096550 17.000000
      vertex -21.383270 -11.096550 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -21.383270 -11.096550 17.000000
      vertex -20.830496 -11.068962 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -20.830496 -11.068962 17.000000
      vertex -20.279785 -11.013855 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -20.279785 -11.013855 17.000000
      vertex -19.732506 -10.931366 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -19.732506 -10.931366 17.000000
      vertex -19.190018 -10.821700 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -19.190018 -10.821700 17.000000
      vertex -18.653671 -10.685129 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 -28.000000 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -32.759998 0.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -32.759998 0.000000 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -32.746201 0.553289 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -32.746201 0.553289 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -32.704842 1.105203 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -32.704842 1.105203 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -32.636021 1.654369 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -32.636021 1.654369 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -32.539913 2.199422 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -32.539913 2.199422 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -32.416759 2.739007 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -32.416759 2.739007 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -32.266857 3.271782 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -32.266857 3.271782 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -32.090588 3.796424 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -32.090588 3.796424 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -31.888386 4.311626 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -31.888386 4.311626 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -31.660755 4.816110 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -31.660755 4.816110 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -31.408260 5.308619 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -31.408260 5.308619 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -31.131529 5.787931 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -31.131529 5.787931 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -30.831251 6.252852 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -30.831251 6.252852 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -30.508171 6.702229 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -30.508171 6.702229 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -30.163094 7.134943 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -30.163094 7.134943 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -29.796875 7.549917 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -29.796875 7.549917 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -29.410429 7.946122 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -29.410429 7.946122 17.000000
      vertex -48.000000 28.000000 17.000000
      vertex -29.004713 8.322572 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -28.580736 8.678329 17.000000
      vertex -29.004713 8.322572 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -28.139555 9.012512 17.000000
      vertex -28.580736 8.678329 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -27.682264 9.324287 17.000000
      vertex -28.139555 9.012512 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -27.209999 9.612882 17.000000
      vertex -27.682264 9.324287 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -26.723938 9.877577 17.000000
      vertex -27.209999 9.612882 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -26.225286 10.117715 17.000000
      vertex -26.723938 9.877577 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -25.715286 10.332699 17.000000
      vertex -26.225286 10.117715 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -25.195202 10.521994 17.000000
      vertex -25.715286 10.332699 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -24.666328 10.685129 17.000000
      vertex -25.195202 10.521994 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -24.129982 10.821700 17.000000
      vertex -24.666328 10.685129 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -23.587494 10.931366 17.000000
      vertex -24.129982 10.821700 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -23.040215 11.013855 17.000000
      vertex -23.587494 10.931366 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -22.489504 11.068962 17.000000
      vertex -23.040215 11.013855 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -21.936731 11.096550 17.000000
      vertex -22.489504 11.068962 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -21.383270 11.096550 17.000000
      vertex -21.936731 11.096550 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -20.830496 11.068962 17.000000
      vertex -21.383270 11.096550 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -20.279785 11.013855 17.000000
      vertex -20.830496 11.068962 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -19.732506 10.931366 17.000000
      vertex -20.279785 11.013855 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -19.190018 10.821700 17.000000
      vertex -19.732506 10.931366 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -13.909572 -7.946122 17.000000
      vertex 13.908571 -7.946122 17.000000
      vertex -14.315288 -8.322572 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -13.523125 -7.549917 17.000000
      vertex 13.522124 -7.549917 17.000000
      vertex -13.909572 -7.946122 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -13.909572 -7.946122 17.000000
      vertex 13.522124 -7.549917 17.000000
      vertex 13.908571 -7.946122 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 13.908571 -7.946122 17.000000
      vertex 14.314287 -8.322572 17.000000
      vertex -14.315288 -8.322572 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -13.156907 -7.134943 17.000000
      vertex 13.155907 -7.134943 17.000000
      vertex -13.523125 -7.549917 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -13.523125 -7.549917 17.000000
      vertex 13.155907 -7.134943 17.000000
      vertex 13.522124 -7.549917 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 14.314287 -8.322572 17.000000
      vertex 14.738263 -8.678329 17.000000
      vertex -14.315288 -8.322572 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -14.315288 -8.322572 17.000000
      vertex 14.738263 -8.678329 17.000000
      vertex -14.739264 -8.678329 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -12.811830 -6.702229 17.000000
      vertex 12.810829 -6.702229 17.000000
      vertex -13.156907 -7.134943 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -13.156907 -7.134943 17.000000
      vertex 12.810829 -6.702229 17.000000
      vertex 13.155907 -7.134943 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -14.739264 -8.678329 17.000000
      vertex 15.179445 -9.012512 17.000000
      vertex -15.180446 -9.012512 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 14.738263 -8.678329 17.000000
      vertex 15.179445 -9.012512 17.000000
      vertex -14.739264 -8.678329 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -12.488750 -6.252852 17.000000
      vertex 12.487750 -6.252852 17.000000
      vertex -12.811830 -6.702229 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -12.811830 -6.702229 17.000000
      vertex 12.487750 -6.252852 17.000000
      vertex 12.810829 -6.702229 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 15.179445 -9.012512 17.000000
      vertex 15.636737 -9.324287 17.000000
      vertex -15.180446 -9.012512 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -15.180446 -9.012512 17.000000
      vertex 15.636737 -9.324287 17.000000
      vertex -15.637736 -9.324287 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -15.637736 -9.324287 17.000000
      vertex 15.636737 -9.324287 17.000000
      vertex -16.110001 -9.612882 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -11.911740 -5.308619 17.000000
      vertex 12.187471 -5.787931 17.000000
      vertex -12.188471 -5.787931 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -12.488750 -6.252852 17.000000
      vertex 12.187471 -5.787931 17.000000
      vertex 12.487750 -6.252852 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -12.188471 -5.787931 17.000000
      vertex 12.187471 -5.787931 17.000000
      vertex -12.488750 -6.252852 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 15.636737 -9.324287 17.000000
      vertex 16.108999 -9.612882 17.000000
      vertex -16.110001 -9.612882 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -11.659245 -4.816110 17.000000
      vertex 11.910741 -5.308619 17.000000
      vertex -11.911740 -5.308619 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.911740 -5.308619 17.000000
      vertex 11.910741 -5.308619 17.000000
      vertex 12.187471 -5.787931 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -16.110001 -9.612882 17.000000
      vertex 16.595062 -9.877577 17.000000
      vertex -16.596062 -9.877577 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 16.108999 -9.612882 17.000000
      vertex 16.595062 -9.877577 17.000000
      vertex -16.110001 -9.612882 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.659245 -4.816110 17.000000
      vertex 11.658246 -4.816110 17.000000
      vertex 11.910741 -5.308619 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -16.596062 -9.877577 17.000000
      vertex 17.093714 -10.117715 17.000000
      vertex -17.094713 -10.117715 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 16.595062 -9.877577 17.000000
      vertex 17.093714 -10.117715 17.000000
      vertex -16.596062 -9.877577 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -11.431614 -4.311626 17.000000
      vertex 11.430614 -4.311626 17.000000
      vertex -11.659245 -4.816110 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.659245 -4.816110 17.000000
      vertex 11.430614 -4.311626 17.000000
      vertex 11.658246 -4.816110 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -17.094713 -10.117715 17.000000
      vertex 17.603714 -10.332699 17.000000
      vertex -17.604715 -10.332699 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -17.604715 -10.332699 17.000000
      vertex 17.603714 -10.332699 17.000000
      vertex -18.124798 -10.521994 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 17.093714 -10.117715 17.000000
      vertex 17.603714 -10.332699 17.000000
      vertex -17.094713 -10.117715 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -11.229412 -3.796424 17.000000
      vertex 11.228412 -3.796424 17.000000
      vertex -11.431614 -4.311626 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.431614 -4.311626 17.000000
      vertex 11.228412 -3.796424 17.000000
      vertex 11.430614 -4.311626 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 17.603714 -10.332699 17.000000
      vertex 18.123798 -10.521994 17.000000
      vertex -18.124798 -10.521994 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -11.053142 -3.271782 17.000000
      vertex 11.052142 -3.271782 17.000000
      vertex -11.229412 -3.796424 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.229412 -3.796424 17.000000
      vertex 11.052142 -3.271782 17.000000
      vertex 11.228412 -3.796424 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -18.653671 -10.685129 17.000000
      vertex 18.652670 -10.685129 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -18.124798 -10.521994 17.000000
      vertex 18.652670 -10.685129 17.000000
      vertex -18.653671 -10.685129 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 18.123798 -10.521994 17.000000
      vertex 18.652670 -10.685129 17.000000
      vertex -18.124798 -10.521994 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -10.903242 -2.739007 17.000000
      vertex 10.902242 -2.739007 17.000000
      vertex -11.053142 -3.271782 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.053142 -3.271782 17.000000
      vertex 10.902242 -2.739007 17.000000
      vertex 11.052142 -3.271782 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -10.780086 -2.199422 17.000000
      vertex 10.779085 -2.199422 17.000000
      vertex -10.903242 -2.739007 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.903242 -2.739007 17.000000
      vertex 10.779085 -2.199422 17.000000
      vertex 10.902242 -2.739007 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -10.683978 -1.654369 17.000000
      vertex 10.682978 -1.654369 17.000000
      vertex -10.780086 -2.199422 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.780086 -2.199422 17.000000
      vertex 10.682978 -1.654369 17.000000
      vertex 10.779085 -2.199422 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -10.573798 -0.553289 17.000000
      vertex 10.614159 -1.105203 17.000000
      vertex -10.615158 -1.105203 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -10.615158 -1.105203 17.000000
      vertex 10.614159 -1.105203 17.000000
      vertex -10.683978 -1.654369 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.683978 -1.654369 17.000000
      vertex 10.614159 -1.105203 17.000000
      vertex 10.682978 -1.654369 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.573798 -0.553289 17.000000
      vertex 10.572798 -0.553289 17.000000
      vertex 10.614159 -1.105203 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex -10.560000 0.000000 17.000000
      vertex 10.559000 0.000000 17.000000
      vertex -10.573798 -0.553289 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.573798 0.553289 17.000000
      vertex 10.559000 0.000000 17.000000
      vertex -10.560000 0.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.573798 -0.553289 17.000000
      vertex 10.559000 0.000000 17.000000
      vertex 10.572798 -0.553289 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.573798 0.553289 17.000000
      vertex 10.572798 0.553289 17.000000
      vertex 10.559000 0.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.683978 1.654369 17.000000
      vertex 10.614159 1.105203 17.000000
      vertex -10.615158 1.105203 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.615158 1.105203 17.000000
      vertex 10.614159 1.105203 17.000000
      vertex -10.573798 0.553289 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.573798 0.553289 17.000000
      vertex 10.614159 1.105203 17.000000
      vertex 10.572798 0.553289 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.780086 2.199422 17.000000
      vertex 10.682978 1.654369 17.000000
      vertex -10.683978 1.654369 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.683978 1.654369 17.000000
      vertex 10.682978 1.654369 17.000000
      vertex 10.614159 1.105203 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.780086 2.199422 17.000000
      vertex 10.779085 2.199422 17.000000
      vertex 10.682978 1.654369 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.053142 3.271782 17.000000
      vertex 10.902242 2.739007 17.000000
      vertex -10.903242 2.739007 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.903242 2.739007 17.000000
      vertex 10.902242 2.739007 17.000000
      vertex -10.780086 2.199422 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -10.780086 2.199422 17.000000
      vertex 10.902242 2.739007 17.000000
      vertex 10.779085 2.199422 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.053142 3.271782 17.000000
      vertex 11.052142 3.271782 17.000000
      vertex 10.902242 2.739007 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.431614 4.311626 17.000000
      vertex 11.228412 3.796424 17.000000
      vertex -11.229412 3.796424 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.229412 3.796424 17.000000
      vertex 11.228412 3.796424 17.000000
      vertex -11.053142 3.271782 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.053142 3.271782 17.000000
      vertex 11.228412 3.796424 17.000000
      vertex 11.052142 3.271782 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.659245 4.816110 17.000000
      vertex 11.430614 4.311626 17.000000
      vertex -11.431614 4.311626 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.431614 4.311626 17.000000
      vertex 11.430614 4.311626 17.000000
      vertex 11.228412 3.796424 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.659245 4.816110 17.000000
      vertex 11.658246 4.816110 17.000000
      vertex 11.430614 4.311626 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.911740 5.308619 17.000000
      vertex 11.910741 5.308619 17.000000
      vertex -11.659245 4.816110 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.659245 4.816110 17.000000
      vertex 11.910741 5.308619 17.000000
      vertex 11.658246 4.816110 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -11.911740 5.308619 17.000000
      vertex 12.187471 5.787931 17.000000
      vertex 11.910741 5.308619 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -12.488750 6.252852 17.000000
      vertex 12.187471 5.787931 17.000000
      vertex -12.188471 5.787931 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -12.188471 5.787931 17.000000
      vertex 12.187471 5.787931 17.000000
      vertex -11.911740 5.308619 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -12.488750 6.252852 17.000000
      vertex 12.487750 6.252852 17.000000
      vertex 12.187471 5.787931 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -12.811830 6.702229 17.000000
      vertex 12.487750 6.252852 17.000000
      vertex -12.488750 6.252852 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -13.156907 7.134943 17.000000
      vertex 12.810829 6.702229 17.000000
      vertex -12.811830 6.702229 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -12.811830 6.702229 17.000000
      vertex 12.810829 6.702229 17.000000
      vertex 12.487750 6.252852 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 28.579737 -8.678329 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 28.138556 -9.012512 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 18.652670 -10.685129 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex -48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 28.138556 -9.012512 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 27.681263 -9.324287 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 27.681263 -9.324287 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 27.209000 -9.612882 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 27.209000 -9.612882 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 26.722939 -9.877577 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 26.722939 -9.877577 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 26.224287 -10.117715 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 26.224287 -10.117715 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 25.714285 -10.332699 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 25.714285 -10.332699 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 25.194202 -10.521994 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 25.194202 -10.521994 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 24.665329 -10.685129 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 24.665329 -10.685129 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 24.128983 -10.821700 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 24.128983 -10.821700 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 23.586494 -10.931366 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 23.586494 -10.931366 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 23.039215 -11.013855 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 23.039215 -11.013855 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 22.488504 -11.068962 17.000000
    endloop
  endfacet
  facet normal 0.000000 -0.000000 -1.000000
    outer loop
      vertex 22.488504 -11.068962 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 21.935730 -11.096550 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 21.935730 -11.096550 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 21.382269 -11.096550 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 21.382269 -11.096550 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 20.829496 -11.068962 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 20.829496 -11.068962 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 20.278786 -11.013855 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 20.278786 -11.013855 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 19.731504 -10.931366 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 19.731504 -10.931366 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 19.189018 -10.821700 17.000000
    endloop
  endfacet
  facet normal -0.000000 -0.000000 -1.000000
    outer loop
      vertex 19.189018 -10.821700 17.000000
      vertex 48.000000 -28.000000 17.000000
      vertex 18.652670 -10.685129 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -13.523125 7.549917 17.000000
      vertex 13.155907 7.134943 17.000000
      vertex -13.156907 7.134943 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -13.156907 7.134943 17.000000
      vertex 13.155907 7.134943 17.000000
      vertex 12.810829 6.702229 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 28.579737 -8.678329 17.000000
      vertex 29.003714 -8.322572 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -13.909572 7.946122 17.000000
      vertex 13.522124 7.549917 17.000000
      vertex -13.523125 7.549917 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -13.523125 7.549917 17.000000
      vertex 13.522124 7.549917 17.000000
      vertex 13.155907 7.134943 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 29.003714 -8.322572 17.000000
      vertex 29.409430 -7.946122 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -14.315288 8.322572 17.000000
      vertex 13.908571 7.946122 17.000000
      vertex -13.909572 7.946122 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -13.909572 7.946122 17.000000
      vertex 13.908571 7.946122 17.000000
      vertex 13.522124 7.549917 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 29.409430 -7.946122 17.000000
      vertex 29.795876 -7.549917 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -14.739264 8.678329 17.000000
      vertex 14.314287 8.322572 17.000000
      vertex -14.315288 8.322572 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -14.315288 8.322572 17.000000
      vertex 14.314287 8.322572 17.000000
      vertex 13.908571 7.946122 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 29.795876 -7.549917 17.000000
      vertex 30.162094 -7.134943 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -15.180446 9.012512 17.000000
      vertex 14.738263 8.678329 17.000000
      vertex -14.739264 8.678329 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -14.739264 8.678329 17.000000
      vertex 14.738263 8.678329 17.000000
      vertex 14.314287 8.322572 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 30.162094 -7.134943 17.000000
      vertex 30.507172 -6.702229 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -15.637736 9.324287 17.000000
      vertex 15.179445 9.012512 17.000000
      vertex -15.180446 9.012512 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -15.180446 9.012512 17.000000
      vertex 15.179445 9.012512 17.000000
      vertex 14.738263 8.678329 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 30.507172 -6.702229 17.000000
      vertex 30.830250 -6.252852 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -15.637736 9.324287 17.000000
      vertex 15.636737 9.324287 17.000000
      vertex 15.179445 9.012512 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 30.830250 -6.252852 17.000000
      vertex 31.130529 -5.787931 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -16.596062 9.877577 17.000000
      vertex 16.108999 9.612882 17.000000
      vertex -16.110001 9.612882 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -16.110001 9.612882 17.000000
      vertex 16.108999 9.612882 17.000000
      vertex -15.637736 9.324287 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -15.637736 9.324287 17.000000
      vertex 16.108999 9.612882 17.000000
      vertex 15.636737 9.324287 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 31.130529 -5.787931 17.000000
      vertex 31.407259 -5.308619 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -17.094713 10.117715 17.000000
      vertex 16.595062 9.877577 17.000000
      vertex -16.596062 9.877577 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -16.596062 9.877577 17.000000
      vertex 16.595062 9.877577 17.000000
      vertex 16.108999 9.612882 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 31.407259 -5.308619 17.000000
      vertex 31.659754 -4.816110 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -17.604715 10.332699 17.000000
      vertex 17.093714 10.117715 17.000000
      vertex -17.094713 10.117715 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -17.094713 10.117715 17.000000
      vertex 17.093714 10.117715 17.000000
      vertex 16.595062 9.877577 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 31.659754 -4.816110 17.000000
      vertex 31.887386 -4.311626 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -18.124798 10.521994 17.000000
      vertex 17.603714 10.332699 17.000000
      vertex -17.604715 10.332699 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -17.604715 10.332699 17.000000
      vertex 17.603714 10.332699 17.000000
      vertex 17.093714 10.117715 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 31.887386 -4.311626 17.000000
      vertex 32.089588 -3.796424 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -18.124798 10.521994 17.000000
      vertex 18.123798 10.521994 17.000000
      vertex 17.603714 10.332699 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.089588 -3.796424 17.000000
      vertex 32.265858 -3.271782 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.265858 -3.271782 17.000000
      vertex 32.415756 -2.739007 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.415756 -2.739007 17.000000
      vertex 32.538914 -2.199422 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.538914 -2.199422 17.000000
      vertex 32.635021 -1.654369 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.635021 -1.654369 17.000000
      vertex 32.703842 -1.105203 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.703842 -1.105203 17.000000
      vertex 32.745201 -0.553289 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.745201 -0.553289 17.000000
      vertex 32.758999 0.000000 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 19.189018 10.821700 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 19.731504 10.931366 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 19.731504 10.931366 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 20.278786 11.013855 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 20.278786 11.013855 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 20.829496 11.068962 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 20.829496 11.068962 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 21.382269 11.096550 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 21.382269 11.096550 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 21.935730 11.096550 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 21.935730 11.096550 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 22.488504 11.068962 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 22.488504 11.068962 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 23.039215 11.013855 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 23.039215 11.013855 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 23.586494 10.931366 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 23.586494 10.931366 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 24.128983 10.821700 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 24.128983 10.821700 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 24.665329 10.685129 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 24.665329 10.685129 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 25.194202 10.521994 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 25.194202 10.521994 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 25.714285 10.332699 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 25.714285 10.332699 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 26.224287 10.117715 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 26.224287 10.117715 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 26.722939 9.877577 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 26.722939 9.877577 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 27.209000 9.612882 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 27.209000 9.612882 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 27.681263 9.324287 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 27.681263 9.324287 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 28.138556 9.012512 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 28.138556 9.012512 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 28.579737 8.678329 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 28.579737 8.678329 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 29.003714 8.322572 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 29.003714 8.322572 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 29.409430 7.946122 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 29.409430 7.946122 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 29.795876 7.549917 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 29.795876 7.549917 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 30.162094 7.134943 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 30.162094 7.134943 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 30.507172 6.702229 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 30.507172 6.702229 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 30.830250 6.252852 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 30.830250 6.252852 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 31.130529 5.787931 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 31.130529 5.787931 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 31.407259 5.308619 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 31.407259 5.308619 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 31.659754 4.816110 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 31.659754 4.816110 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 31.887386 4.311626 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 31.887386 4.311626 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 32.089588 3.796424 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.089588 3.796424 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 32.265858 3.271782 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.265858 3.271782 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 32.415756 2.739007 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.415756 2.739007 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 32.538914 2.199422 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.538914 2.199422 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 32.635021 1.654369 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.635021 1.654369 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 32.703842 1.105203 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.703842 1.105203 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 32.745201 0.553289 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.745201 0.553289 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 32.758999 0.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex 32.758999 0.000000 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 48.000000 -28.000000 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex 48.000000 28.000000 17.000000
      vertex 19.189018 10.821700 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex 19.189018 10.821700 17.000000
      vertex 18.652670 10.685129 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex 18.652670 10.685129 17.000000
      vertex 18.123798 10.521994 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex 18.123798 10.521994 17.000000
      vertex -18.653671 10.685129 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -48.000000 28.000000 17.000000
      vertex -18.653671 10.685129 17.000000
      vertex -19.190018 10.821700 17.000000
    endloop
  endfacet
  facet normal 0.000000 0.000000 -1.000000
    outer loop
      vertex -18.653671 10.685129 17.000000
      vertex 18.123798 10.521994 17.000000
      vertex -18.124798 10.521994 17.000000
    endloop
  endfacet
endsolid Mesh
```
