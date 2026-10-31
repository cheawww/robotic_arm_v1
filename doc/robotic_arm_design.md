# Current robot-arm design brief

Updated **2026-10-29**. This is a concept brief based on the conversation. The gearbox has CAD and movement checks; a complete robot arm has not yet been dimensioned, built or load-qualified.

## Requirements and open choices

| Item | Status |
|---|---|
| Horizontal shoulder-to-gripper reach | User confirmed 500 mm |
| Payload | Discussed 500 g target at reach; not a demonstrated capacity |
| Motor | AEI.th NEMA 17 42BYGH40, Designed in Thailand, lot 032025, AEIS Electronics Supply (Thailand) Co., Ltd., as reported by the user |
| Printer | User's Bambu Lab P2S |
| Candidate print materials | User can use PLA or PETG; final print process is not locked |
| Current gearbox | Two fixed-ring 4:1 stages, total 16:1 |
| Drive architecture across the arm | Still a design choice; planetary, remote belt and combined drives have been discussed |
| Required speed, duty cycle and accuracy | Not established |

500 mm here means **horizontal reach**, not upright arm height. There is no single required or standard overall height for this project. Set base height and link proportions from the intended workspace, joint limits and stability requirement.

## Joint concept

The discussed five-axis concept is base yaw, shoulder pitch, elbow pitch, forearm roll and wrist pitch, plus a separate gripper actuator. This is a proposed architecture, not a completed joint drawing set.

Shoulder and elbow gravity loads are likely to drive sizing in an extended pose. A vertical base-yaw axis has no ideal static gravity torque about its own vertical axis, but it still needs acceleration torque, friction allowance and bearings that support the arm's overturning moment. Roll and wrist loads depend on payload offset and pose; they must not be universally assigned zero torque.

A **working study layout** is 220 mm shoulder-to-elbow + 200 mm elbow-to-wrist + 80 mm wrist-to-tool = 500 mm. These are axis-to-axis/tool distances, not the lengths of rectangular blank parts. The user has not approved them as final manufactured link lengths. The extra forearm-roll barrel, wrist bracket and gripper must fit within the final 80 mm allocation, rather than being added on top of it. If they do not fit, rebalance the three allocations while retaining the 500 mm total and recalculate every affected lever arm.

Place heavy motors close to the base/shoulder where practical. Moving a motor proximally reduces its gravity lever arm, but the belt, pulleys, shafts, tensioning hardware and output bearings still contribute mass and loads.

## Motor information

The user's approximately **25 mm shaft projection** supersedes the shorter provisional shaft outline previously borrowed from a different motor drawing. A 5 mm shaft and a roughly 42 x 42 x 40 mm body remain working envelopes to confirm against the actual motor.

The exact AEI motor's current, resistance, inductance, holding torque and torque-speed curve have not been established. The supplied LDO datasheet is for a different motor and is not used to assign AEI electrical or torque ratings. NEMA 17 describes a frame size and does not establish available torque.

The motor-plate CAD uses M3 mounting clearances and an approximately 31.1 mm mounting square. Measure the physical motor's mounting square, pilot, shaft diameter, shaft flat and available thread depth before finalizing its interface.

The native gearbox animation runs at about 9.55 rpm input solely for visibility. That speed is not an AEI motor test result. Motor sun fixation is by set screws; the printed hub's retention remains to be tested.

## Transmission choices discussed

| Arrangement | Nominal total reduction |
|---|---:|
| One planetary stage | 4:1 |
| Two planetary stages | 16:1 |
| Example belt reduction | 5:1 |
| 5:1 belt plus one planetary stage | 20:1 |
| 5:1 belt plus two planetary stages | 80:1 |

Only the two-stage planetary mechanism currently has the verified native moving assembly. Belt ratio, pulley dimensions, belt width, tension and belt-driven arm layout are not a finalized CAD design. A larger reduction trades speed for torque and does not establish tooth, shaft, bearing or housing strength.

## Performance and control decisions still needed

Use the actual motor's running torque at the selected speed and driver conditions. Do not treat holding torque as available running torque. Choose the driver and power supply after confirming motor ratings; a development sketch is not a verified motor protection system.

Measure component masses and centres of gravity, specify acceleration and duty cycle, then calculate each joint. Provide a deliberate power-loss strategy such as counterbalance, brake or controlled restraint. A 16:1 planetary reducer is not assumed self-locking, and a powered stepper is not a passive brake.

See [stability_analysis.md](stability_analysis.md) for the fresh, explicitly assumed torque example and the measurements needed to replace it.

## Practical structure carried forward from the archive

| Module | Current design approach | Detail to resolve before its CAD is released |
|---|---|---|
| Base | Rigid workbench-mounted platform initially; separate lightweight electronics enclosure | Mounting structure, anchors and load transfer to the bench |
| Yaw | Supported turntable/hub with motor drive acting on it | Bearing arrangement for weight and overturning moment; cable-limited range |
| Shoulder | Two-sided fork/U-bracket, cross-braced and gusseted | Joint shaft, bearing span, driven gear/hub and counterbalance attachment |
| Upper arm | Hollow beam with local ribs and a continuous load path through the joint adapters | Working 220 mm centre distance, actual section stiffness and mass |
| Elbow | Compact two-sided fork with a supported joint shaft | Working 200 mm elbow-to-wrist distance and actual distal mass |
| Forearm | Lighter hollow link with protected cable route | Torsional stiffness, adapter stiffness and cable bend space |
| Roll/wrist | Bearing-supported rotating hub and compact pitch clevis | Actuator, physical range and total wrist/tool offset |
| Gripper/camera | Lightweight removable tool plate, mechanical finger stops and compliant contact pads | Actual grip force, opening, tool mass and camera offset |

The archived component shapes are useful starting concepts. Its P01-P31 dimensions are not a current drawing set. In particular, a 6804 bearing uses a 20 x 32 x 7 mm basic envelope; the archived 22 mm bearing pocket was incompatible. That bearing has not been selected for this arm; shaft diameter, loads, bearing spacing and fits must be selected together. [EZO manufacturer data](https://www.ezo-brg.co.jp/english/product/spec.php?eid=01927)

A two-bearing or other moment-capable joint support should take structural loads through the fork/base. Do not hang the upper arm directly on the motor shaft, a servo spline or the unsupported printed helical output. A gearbox housing is not automatically a complete joint-bearing module.

## Coordinates and joint count

Use the existing CAD convention **X forward, Y up, Z lateral** for the arm study. Its positive base-yaw axis is Y; shoulder/elbow pitch axes are lateral. The gearbox's local Y shaft axis is rotated into the required joint axis when installed.

If later exporting to an X-forward, Y-left, Z-up software frame, one consistent right-handed mapping is `X_software=X_CAD`, `Y_software=-Z_CAD`, `Z_software=Y_CAD`. Apply this transform to axes, inertia and mesh orientation consistently. Do not silently mix the archive's Z-up assembly coordinates with the current gearbox convention.

The present concept has **five arm motion axes, including base yaw, plus gripper opening**. A second tool-roll actuator would be an optional extra axis and mass, not a free duplicate of the existing forearm roll. A fixed-base arm does not automatically need mobile-robot `map/odom` frames.

## Control and power architecture

Begin with one joint: a host/manual interface sends targets to a microcontroller that generates the selected driver's command signals. Add homing, direction checks, acceleration ramps and mechanical/cable travel limits before adding higher-level planning. Add vision and an optional ROS/MoveIt-style planner only after the mechanical joint and low-level controller work reproducibly; no software release/version is prescribed here.

Use a suitable current-regulated stepper driver after confirming the motor's phase-current rating and the actual board's voltage, current and cooling limits. A TMC2209-class STEP/DIR driver is an example, not an automatic match for every NEMA 17 or NEMA 23 motor. The manufacturer's IC specifications also do not establish the continuous rating of an arbitrary carrier board. [Analog Devices TMC2209 documentation](https://www.analog.com/en/products/tmc2209.html)

Existing Arduino Mega/H-bridge test sketches under `../non-me/code/` are development work. Wave-stepping H-bridge outputs are not interchangeable with STEP/DIR driver inputs, and a fixed PWM duty does not establish coil-current regulation. Specify and implement the driver interface deliberately before reusing firmware.

Select motor, servo and logic supply rails for the purchased hardware. Do not automatically buy the archive's 24 V 10 A supply or assign it a balancing mass. Keep power-loss support, hardware stopping and cable restraint as part of the physical design, not only planner settings.
