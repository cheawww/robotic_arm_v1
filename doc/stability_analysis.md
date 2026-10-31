# Current torque and stability calculations

Updated **2026-10-29**. Recomputed for this documentation revision. The mass budget below is a transparent example, not measured robot-arm data or a payload rating.

## Confirmed target and calculation rules

The user confirmed **500 mm maximum horizontal shoulder-to-gripper reach**. The discussed payload goal is 500 g. Use metres, kilograms and N.m, with `g = 9.80665 m/s^2`.

For the straight horizontal reference pose:

`joint gravity torque = sum(mass x g x horizontal lever arm from that joint)`

For other poses, use `torque about joint axis = axis dot sum(r cross force)`. A pose's visual height is not automatically its gravity lever arm. Add inertia, acceleration, friction and transmission reactions separately.

## Payload alone

Shoulder: `0.500 x 9.80665 x 0.500 = 2.4516625 N.m`.

For an illustrative elbow 220 mm from the shoulder, the payload is 280 mm beyond the elbow:

Elbow: `0.500 x 9.80665 x 0.280 = 1.372931 N.m`.

These calculations exclude the arm and tool masses.

## Fresh illustrative mass budget

Assume straight reach segments of 220 / 200 / 80 mm. Component centre positions below are measured horizontally from the shoulder. No row is a measured printed-part mass.

| Component | Assumed mass, kg | Shoulder distance, m | Shoulder torque, N.m | Elbow torque, N.m |
|---|---:|---:|---:|---:|
| Payload | 0.500 | 0.500 | 2.451663 | 1.372931 |
| Gripper and camera | 0.120 | 0.460 | 0.541327 | 0.282432 |
| Wrist assembly | 0.160 | 0.420 | 0.659007 | 0.313813 |
| Forearm structure | 0.150 | 0.320 | 0.470719 | 0.147100 |
| Elbow gearbox/bracket | 0.200 | 0.220 | 0.431493 | 0 |
| Upper-arm structure | 0.180 | 0.110 | 0.194172 | Not downstream of elbow |
| **Total** | | | **4.748380** | **2.116275** |

A motor placed exactly at the shoulder axis contributes no shoulder gravity moment in this simplified example. Its actual offset, bracket and pulley mass must be added. The example does not silently include a 280 g motor at every joint. Weigh the real assemblies and account for every component once.

An illustrative design multiplier of 2 would give **9.496760 N.m shoulder** and **4.232550 N.m elbow**. This multiplier is an example allowance, not a universally sufficient safety factor or a substitute for acceleration and strength calculations.

## Available motor torque is unknown

No exact AEI 42BYGH40 torque-speed curve has been established. The previous conversational assumption of 4 kgf.cm must not be treated as a verified running torque. The exact driver, current limit, supply, speed and thermal conditions matter.

Use:

`estimated output torque = motor running torque at operating speed x total reduction x assumed efficiency`

`output speed = motor speed / total reduction`

The following is **arithmetic only**, using a hypothetical 0.200 N.m motor torque and 100 rpm input. Assume 0.85 efficiency per planetary stage and 0.95 for the belt; none is measured on this gearbox.

| Arrangement | Reduction | Assumed total efficiency | Calculated output torque | Output speed |
|---|---:|---:|---:|---:|
| Two planetary stages | 16 | 0.7225 | 2.312 N.m | 6.25 rpm |
| 5:1 belt + one planetary stage | 20 | 0.8075 | 3.230 N.m | 5 rpm |
| 5:1 belt + two planetary stages | 80 | 0.686375 | 10.982 N.m | 1.25 rpm |

These numbers are not this motor's performance and do not validate any arrangement for the arm. Increasing motor speed to regain output speed changes its available torque. Printed teeth, pins, set screws, bearings, housing threads and output support can limit usable torque well before an ideal multiplication estimate.

For context, `1 kgf.cm = 0.0980665 N.m`; do not mix kg, kgf.cm and N.m as interchangeable quantities.

## Shorter reach and counterbalance

For a fixed payload mass, reducing horizontal reach reduces payload gravity torque in direct proportion. Link self-weight scales differently if link dimensions or masses change, so do not reduce the complete arm torque by a single percentage without updating its mass model.

Remote motors, lighter distal parts, a counterweight, a spring/gas-spring counterbalance, a different motor or a higher reduction are design options. A 5:1 belt plus 4:1 planetary is not the only possible solution and cannot be promised to lift 500 g from the current evidence.

## Base stability

Joint torque and resistance to tipping are different checks. Determine the whole assembly's centre of mass, including the base, motor mounts and any ballast. In a static unanchored case, its ground projection must remain within the support polygon with an appropriate margin. Dynamic acceleration, external contact and power-loss motion also matter.

Base footprint, base mass, shoulder position and anchors have not been physically specified. Therefore no approved minimum base size or counterweight is assigned. The later footprint table is a recalculated layout example. A gearbox's torque rating alone would not establish stability.

### Required motor torque: use the example as a selection test

For the same illustrative mass budget and multiplier 2, rearrange the transmission equation:

`required motor running torque = design joint torque / (total reduction x assumed efficiency)`

Assume the downstream output-gear mesh is 1:1 for this comparison. The table includes only the stated belt/planetary efficiencies, with no additional loss allowance for that final mesh, so the motor requirements are optimistic with respect to any extra mesh loss. Include the actual final ratio and efficiency when selected. A reference final joint speed of 1 rpm is used only to show the motor operating point; it is not an approved arm speed.

| Drive before the assumed 1:1 final mesh | Motor rpm for 1 rpm joint | Required shoulder motor torque | Required elbow motor torque |
|---|---:|---:|---:|
| 16:1 planetary | 16 | 0.822 N.m | 0.366 N.m |
| 20:1 belt/planetary | 20 | 0.588 N.m | 0.262 N.m |
| 80:1 belt/two-stage planetary | 80 | 0.173 N.m | 0.077 N.m |

Use actual measured/qualified running torque at the motor rpm corresponding to the desired joint speed. A 4 kgf.cm holding-torque assumption or a larger NEMA frame name does not answer that comparison. An added 80:1 reduction is an option to evaluate, not the selected final arm drive or proof that printed teeth can sustain its output.

### Revised base example from the archived footprint idea

For layout only, consider a centred **350 x 260 mm** support footprint with the shoulder's horizontal projection at its centre, and the arm extending along the 350 mm direction. The front support edge is then 175 mm away. This footprint is a proposal, not measured base hardware. Its two-dimensional support polygon and all yaw directions must ultimately be checked.

The present moving-mass example, including 500 g payload, totals **1.310 kg** with first moment **0.4842 kg.m** about the shoulder. If all fixed mass has its centre at X = 0:

`whole-system COM_x = 0.4842 / (fixed_mass + 1.310)`

| Assumed fixed mass at centre | Whole-system mass | COM radius for this pose | Front-edge margin | Minimum margin over all yaw angles |
|---|---:|---:|---:|---:|
| 1 kg | 2.310 kg | 209.6 mm | -34.6 mm | -79.6 mm |
| 2 kg | 3.310 kg | 146.3 mm | 28.7 mm | -16.3 mm |
| 3 kg | 4.310 kg | 112.3 mm | 62.7 mm | 17.7 mm |

The front-only zero-margin fixed mass is about **1.457 kg**, but the narrower side support half-width is 130 mm. Allowing all yaw angles raises the zero-margin fixed mass to about **2.415 kg** for this particular centred static example. Zero margin is not an acceptable design target. The 2 kg row passes the front-edge calculation yet extends outside a side edge after yaw; the 3 kg row has only 17.7 mm minimum static margin. Neither is a payload rating or an instruction to buy a particular base mass. Include actual shoulder offsets, omitted masses, acceleration and support contact locations before using a result physically.

For a current total mass `M` and first moment `S`, added ballast `m_b` at position `x_b` can be calculated for a chosen front COM limit `x_limit`:

`m_b >= max(0, (S - x_limit*M) / (x_limit - x_b))`, with `x_b < x_limit`.

Rear placement of existing heavy components is useful when it creates a real opposing moment. Extending only the rear footprint does not move the front tipping edge forward. Bench anchors transfer overturning forces into the supporting structure; they do not make the links, gearbox or table strong enough for an arbitrary payload. Initial arm development should use a properly mounted workbench rig rather than rely on an unweighed enclosure/PSU as ballast.

### Why the helical output needs support

If the final 15-tooth output gear carries the example shoulder torque through a 1:1 external mesh, its nominal pitch diameter is 18.75 mm. Its audited helix lead gives a nominal pitch-cylinder helix angle near 20 degrees. Then:

`tangential mesh force Ft = 2*T / pitch_diameter_m`

`axial mesh force Fa = Ft*tan(helix_angle)`

At **4.748 N.m** static torque, these give approximately **506 N tangential** and **184 N axial**. Both double if the illustrative design torque is doubled. These are assumed-load calculations, not observed gearbox capability, and do not include the radial separating force or bearing reactions. They show why a 23.25 mm clearance opening and unsupported printed gear cannot be treated as a complete load-bearing joint. [KHK manufacturer gear-force reference](https://www.khkgears.co.jp/gear_technology/intermediate_guide/khk423_1/)

## Measurements needed for a rated arm

Record actual link lengths and mass/centre-of-gravity data; payload/tool offsets; motor torque at the intended operating speed and driver settings; joint acceleration and duty cycle; bearing and thrust load paths; backlash/deflection; and restrained loaded test results. Complete the pending planet-bearing seats, central/output support and fastening tests first.

All numerical inputs and results above are reproduced in [current_calculations.json](current_calculations.json). The current supported conclusion is a verified 16:1 movement concept with unfinished physical interfaces and unverified robot-arm payload capacity. The fabrication order and what to measure at each stage are in [BUILD_PLAN.md](BUILD_PLAN.md).
