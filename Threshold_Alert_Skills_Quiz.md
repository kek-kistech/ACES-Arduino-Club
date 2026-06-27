# Threshold Alert — Embedded Systems Skills Quiz

*ACES KNUST — Arduino  Club*

A self-paced practice build: wire a potentiometer, an RGB LED, and a buzzer — then write the logic yourself. No code is provided here on purpose. This is a check of what you actually understand, not a copy-paste exercise.

## Contents

- [What you're building](#what-youre-building)
- [The three zones](#the-three-zones)
- [Why this format](#why-this-format)
- [What you'll need](#what-youll-need)
- [Build it in stages](#build-it-in-stages--verify-each-piece-before-adding-the-next)
- [What your code needs to do](#what-your-code-needs-to-do)
- [Functions you'll likely need](#functions-youll-likely-need)
- [Troubleshooting](#troubleshooting)
- [Self-check rubric](#self-check-rubric--100-points)

## What you're building

A potentiometer stands in for a real-world sensor — a fire alarm, a water-level gauge, a proximity sensor, whatever story you want to tell. Depending on how far it's turned, your circuit must react in one of three zones: **Safe**, **Warning**, or **Danger**.

| | |
|---|---|
| **Format** | Self-paced practice build |
| **Components** | Potentiometer, RGB LED, buzzer |
| **Target build time** | 30 minutes |
| **Difficulty** | Foundation — 3 components, 3 zones |

> **The one question that decides everything**
> *Does your circuit show the right color and sound at the right reading — instantly, every time?*

## The three zones

| Zone | Condition | Required output |
|---|---|---|
| Safe | Reading below Threshold A | LED green, buzzer off |
| Warning | Reading between A and B | LED amber (red + green), buzzer off |
| Danger | Reading above Threshold B | LED blinking red, buzzer sounding |

You choose your own Threshold A and Threshold B. There's no single correct number — just values that give you a clearly distinguishable middle zone once you test it.

## Why this format

This is a clean test of one specific skill: turning a single continuous reading into layered decision logic with two coordinated outputs. No sensors to calibrate, no libraries to fight — just reading an input, a couple of comparisons, and getting the wiring right.

## What you'll need

| Component | Pin | Notes |
|---|---|---|
| Potentiometer wiper (middle leg) | A0 | Outer legs to 5V and GND |
| RGB LED — Red leg | D9 | Through a 220–330Ω resistor |
| RGB LED — Green leg | D10 | Through a 220–330Ω resistor |
| RGB LED — Blue leg | D11 | Through a 220–330Ω resistor |
| RGB LED — common leg | GND | No resistor on this leg |
| Buzzer + | D8 | Buzzer − to GND |

## Build it in stages — verify each piece before adding the next

1. **Power rails.** Run a wire from Arduino 5V to the breadboard's red rail, and Arduino GND to the blue rail. Everything else taps into these.
2. **Potentiometer, tested alone.** Wire it per the pin map. Write a short test sketch that reads the pot and prints the value to the Serial Monitor. Turn it fully both ways — you should see numbers sweep roughly from 0 to 1023. If nothing moves, recheck the outer-leg wiring before going further.
3. **RGB LED, tested alone.** Wire it, guessing common cathode first (common leg to GND). Write a quick test that lights red, then green, then blue, half a second each. If colors come on backwards — everything lit by default, turning *off* when you'd expect *on* — your LED is common anode: move the common leg to 5V instead, and remember every on/off in your final logic will need flipping.
4. **Buzzer, tested alone.** Toggle it on and off with a short pause between. A continuous tone means it's an active buzzer — straightforward on/off control works. A faint click only means it's a passive piezo — you'll want a tone-generating approach instead of a plain on/off signal.
5. **Combine.** Once every piece works on its own, wire it all together and write the full logic described below.

## What your code needs to do

- Continuously read the potentiometer.
- Compare the reading against your two thresholds.
- Below Threshold A → steady green, buzzer off.
- Between A and B → steady amber (red + green together), buzzer off.
- At or above Threshold B → blinking red, buzzer sounding.
- The blink can be done with a simple, repeated on/off/pause pattern — nothing else needs to keep running at the same time in this version, so briefly pausing the whole program for the blink is fine here.

## Functions you'll likely need

Look these up by name on the official reference rather than guessing at their behaviour:

- **analogRead()** — reads a voltage between 0 and 1023 from the potentiometer.
- **digitalWrite()** — turns a pin fully on or off; this is how each RGB color and the buzzer are controlled.
- **if / else if / else** — branches your logic into the three zones.
- **delay()** — pauses execution; used here to create the blink in Danger.

**Official Arduino Language Reference:** <https://docs.arduino.cc/language-reference/>
Search any function by name there for a short explanation and a working example — check there before searching anywhere else.

## Troubleshooting

- **LED won't turn off, or stays dim:** check the resistor is on a color leg, not the common leg.
- **Colors look muddy instead of a clean red/green/amber:** uneven brightness balance between channels is common on cheap RGB LEDs — try a slightly higher-value resistor on whichever color is overpowering.
- **Reading jumps around erratically:** almost always a loose jumper on the pot's wiper leg — reseat it.
- **One zone never seems to trigger:** your thresholds may not match the pot's real achievable range — rerun the Stage 2 test and check the actual min/max values you see before fixing your thresholds.

## Self-check rubric — 100 points

Score your own build honestly once it's working. It's worth getting used to this structure now — it's the same one used for live evaluation.

| Criterion | Points | What it means |
|---|---|---|
| Circuit correctness | 30 | Is the breadboard wired the way the task required? Are connections and components placed correctly? |
| Functionality | 30 | Does it actually do what was asked when tested? Full marks for fully working; partial credit for partially working. |
| Code quality & logic | 20 | Is the code correct and sensible — written and understood, not just guessed or copied? |
| Understanding | 10 | Can you explain what you built, and troubleshoot it on the spot, if someone asks? |
| Completion time | 10 | A small bonus only — it never outweighs a working, well-understood build. |

> **Worth repeating:** finishing fast only helps if your circuit and code also work. A correctly reasoned, mostly-working build beats a fast, broken one every time.
