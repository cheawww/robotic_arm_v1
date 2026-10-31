# Part identification and payload guide

Updated **2026-10-29**. This guide identifies the current parts and separates the intended payload from tested performance.

## Identify the printed parts

| Source part | Appearance and purpose | Quantity for two stages |
|---|---|---:|
| `motor plate.SLDPRT` | Stationary round motor mount with a cavity for the first front carrier and case fixing holes | 1 |
| `ring gear.SLDPRT` | Stationary cylinder with internal helical teeth spanning both stages | 1 |
| `sun gear.SLDPRT` | Small 15-tooth input gear with an added motor-shaft hub and set-screw features | 1 |
| `plenetary gear.SLDPRT` | Small 15-tooth gears orbiting the sun, each with a central bearing bore | 6 |
| `gear carrier.SLDPRT` | Plain 52 mm annular front plate, 5 mm thick, three planet-pin holes and a 22 mm centre opening | 2 |
| `gear carrier-2.SLDPRT` | Rear 52 mm carrier plate with an integral central helical gear about 20 mm long | 2 |
| `end plate.SLDPRT` | Stationary outer cover, 70 mm diameter and 10 mm total height, with a 23.25 mm output passage | 1 |

The first six rows account for 13 printed instances in the existing moving assembly. The new end plate would bring the proposed printed-part count to 14; it has only been included in a separate static fit check so far.

## Follow the power path

Motor shaft -> separate sun -> first three planets -> first carrier pair -> first carrier-2 integral gear -> second three planets -> second carrier pair -> final carrier-2 integral helical output.

The ring and outer plates stay fixed. Both plates within a carrier pair turn together. All three planets must be installed in each stage. The final output is **carrier 2**, not the plain carrier-1 plate.

## Bearings and small clearances

Two selected 685ZZ bearings per planet give a nominal 10 mm bearing stack. Their 11 mm outside diameter does not fit the current 10 mm CAD bore; bearing-seat revision is still pending. A suitable printed fit must be determined with the actual bearings and material.

The output gear's maximum diameter is 21.25 mm; the end-plate passage is 23.25 mm. This gives **1 mm radial clearance** at that opening. It is intentional clearance around the rotating gear, not a bearing fit.

Small visible gear clearance may be consistent with backlash and printed tolerances. The user's physical observation that the gears remain meshed while moving is encouraging fit information, but it does not quantify backlash or establish load capacity. Check for binding, tooth skipping, axial rubbing, loose pins and increasing wear over a full rotation.

Helical gears also generate axial reactions under load. Bearing and plate retention must carry these reactions without clamping a rotating bearing outer ring or forcing a gear against a stationary cover.

## What 500 g at 500 mm means

For a horizontal payload lever arm:

`gravity torque = payload mass x 9.80665 x horizontal distance`

| Payload at 500 mm | Payload-only shoulder gravity torque |
|---|---:|
| 250 g | 1.226 N.m |
| 500 g | 2.452 N.m |

These values exclude every link, bearing, motor, gearbox, wrist, gripper and camera. They are not the total torque the shoulder must deliver.

The current illustrative mass budget, fully stated in [stability_analysis.md](stability_analysis.md), gives 4.748 N.m at the shoulder and 2.116 N.m at the elbow in a straight horizontal reference pose. No mass in that example is presented as a measured part mass. Actual PLA/PETG printed mass depends on geometry, walls, infill and hardware.

## How to evaluate the prototype

Complete the pending bearing seats and fastening details first. Confirm smooth hand rotation and secure retention without a payload. Use restrained, incremental tests with measured masses and lever arms; record input speed, motor current/temperature, missed steps, backlash and visible damage. The test arrangement must prevent a falling arm if power or torque is lost.

The existing movement check establishes kinematics. A useful payload rating requires complete joint support, a verified drive at operating speed, structural checks and repeatable loaded tests. No current document declares the arm ready to lift 500 g at full reach.

## Future arm modules: shapes rather than unverified dimensions

Retain the archive's practical layout ideas: a rigid base with separate enclosure, a supported yaw hub, gusseted two-sided shoulder/elbow forks, hollow ribbed links, a compact roll barrel and wrist clevis, and a removable gripper/camera plate. Build these around the actual bearing and actuator envelopes rather than reusing the former P01-P31 sizes. The 220 / 200 / 80 mm study allocation must include all distal adapters and the gripper.

For clear CAD inspection, distinguish fixed housing, rotating carriers, planet gears, bearings and metal pins with different appearances. Colour does not define material, strength or whether a component is fixed; keep the feature, mate and BOM descriptions explicit.

## Backlash, friction and restraint

To measure backlash, hold the input at a repeatable position and gently reverse the output without moving the input. Record the free angular movement. If measuring a tangential displacement `s` at radius `r`, use `angle_rad approximately s/r` for small angles. Record the method and load so later revisions are comparable. Motor microstep size is not a backlash or positioning-accuracy measurement.

The bearing outer rings must be retained in the rotating planet; the inner-ring clamp stack stays with the pins. Helical thrust needs a deliberate path to an appropriate bearing/retainer. A closed cover that prevents parts falling out does not by itself provide that path.

Gripper payload also depends on contact friction and geometry. For a symmetric two-jaw vertical friction grip, the ideal minimum normal force per jaw is `payload_weight / (2 x friction_coefficient)`, before dynamic allowance. Neither servo stall torque nor a guessed gripper label establishes that force. Measure it at the real finger extension and contact pads.

Use the practical sequence and record sheets in [BUILD_PLAN.md](BUILD_PLAN.md). Complete the hand-fit stage before powered testing, and provide actual radial/axial support before adding an external driven gear or arm load.
