# Planetary ratios and carrier geometry

Updated **2026-10-29**. This describes the discussed mechanism and recomputes its nominal geometry. Dimensional compatibility and kinematic ratios do not establish a manufactured gear's strength or tooth-contact quality.

## One stage

Each stage uses a 15-tooth sun, three 15-tooth planets and a fixed 45-tooth internal ring. The sun is the input and the carrier pair is the output.

For a fixed ring:

`reduction i = sun speed / carrier speed = 1 + ring teeth / sun teeth`

`i = 1 + 45 / 15 = 4`

The carrier turns in the same direction as the sun. The 45:15 tooth-count ratio alone is 3; the complete fixed-ring planetary reduction is **4:1**.

Two identical stages in series give:

`i_total = 4 x 4 = 16`

Sixteen input turns produce one final output turn. A hypothetical 100 rpm input produces 25 rpm at stage 1 and 6.25 rpm at the final carrier. These speeds do not establish that the actual motor can supply the required torque at 100 rpm.

## Geometry calculations

The nominal transverse module is 1.25 mm, consistent with the 37.5 mm carrier PCD and the 21.25 mm external-gear tip diameter.

| Quantity | Calculation | Result |
|---|---|---:|
| Sun pitch diameter | 1.25 x 15 | 18.75 mm |
| Planet pitch diameter | 1.25 x 15 | 18.75 mm |
| Ring pitch diameter | 1.25 x 45 | 56.25 mm |
| Sun-to-planet centre distance | (18.75 + 18.75) / 2 | 18.75 mm |
| Carrier pin pitch-circle diameter | 2 x 18.75 | 37.5 mm |
| External-gear nominal tip diameter | 1.25 x (15 + 2) | 21.25 mm |
| Adjacent planet-centre spacing | 2 x 18.75 x sin(60 degrees) | 32.476 mm |
| Gap between adjacent maximum planet-diameter envelopes | 32.476 - 21.25 | 11.226 mm |

The nominal tooth-count condition is satisfied: `45 = 15 + 2 x 15`. The equally spaced three-planet assembly condition is also satisfied: `(45 + 15) / 3 = 20`, an integer. These conditions do not replace actual tooth phasing during assembly.

Use **three pin holes at 120 degrees on a 37.5 mm PCD**, centred on the carrier axis. PCD is a hole-position diameter; it is not the carrier's outside diameter. The saved plates are 52 mm outside diameter and 5 mm thick.

## Carrier roles

There are **four plates**, not two plates shared across both stages. Carrier 1 is a plain annular plate. Carrier 2 has the integral helical gear. Each stage's two plates rotate together through its three planet pins. The first carrier-2 gear is the next stage's sun; the last carrier-2 gear transmits the final output.

## Planet spin and native mates

For equal sun and planet tooth counts, measured about the same fixed axis direction:

`planet speed = 2 x carrier speed - sun speed`

| Component | Speed relative to motor input |
|---|---:|
| Motor sun | 1 |
| Stage-1 carrier pair / stage-2 sun | 1/4 |
| Stage-1 planet absolute spin | -1/2 |
| Final carrier pair | 1/16 |
| Stage-2 planet absolute spin | -1/8 |

Planet centres also orbit with their carriers. A planet's absolute spin is different from its rotation relative to the carrier.

The verified native assembly uses two 4:1 reduction mates and six 1:1 external sun/planet tooth-ratio mates. Its moving carrier references produce the required relative motion. Arbitrarily replacing the planet mates with an absolute 2:1 ratio is not the same constraint.

## Axial width and helical geometry

Planet gears are 10 mm wide. The carrier-2 integral gears are about 20 mm long. The existing ring is 42 mm high. The stack is given in [the gearbox layout](BASE_GEARBOX_DESIGN.md).

The audited sun/planet helix pitch is 161.84 mm; the ring helix pitch is 485.52 mm. Do not substitute normal module for transverse module or independently mirror one gear without checking helix hand, axis orientation and tooth phase. A shared CAD mate ratio cannot correct an incompatible tooth profile.

Nominal tooth counts and carrier coordinates determine reduction and placement. They do not determine final backlash, bearing fit or print allowance. Preserve the existing measured geometry while correcting the explicitly identified holes; verify printed meshing through a complete cycle before load testing.

## Coordinates for future CAD edits

Use local in-plane coordinates **u, v** and a separate axial height coordinate. In the audited source parts the carrier pattern starts at the top of the plate:

| Pin | u, mm | v, mm |
|---|---:|---:|
| 1 | 0 | 18.750000 |
| 2 | -16.237976 | -9.375000 |
| 3 | 16.237976 | -9.375000 |

A rigid rotation of the entire carrier pattern preserves PCD, but individual gears still need the correct tooth phase. Preserve the source pattern orientation when comparing the existing assembly.

The six case-hole centres on the separate 65 mm PCD are `(0,32.5)`, `(-28.145826,16.25)`, `(-28.145826,-16.25)`, `(0,-32.5)`, `(28.145826,-16.25)`, `(28.145826,16.25)`. Do not confuse that case pattern with the 37.5 mm planet-pin pattern.

## Extra output gearing

The existing 16:1 reduction is measured at the final carrier-2 integral gear. If that 15-tooth gear subsequently drives an external gear of `Z_driven` teeth, the additional ideal reduction is `Z_driven / 15` and its direction reverses. Thus `motor-to-joint reduction = 16 x Z_driven / 15`, before any belt stage. The driven gear and joint centre distance are not selected in the current CAD, so do not assign the arm a final joint reduction from the planetary value alone.

This also explains why the supported joint shaft and its driven gear must be designed together. Preserve the 500 mm shoulder-to-tool reach allocation when accommodating the extra mesh and wrist/tool offsets.
