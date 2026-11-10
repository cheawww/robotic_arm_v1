# Two-stage planetary gearbox

Open [planetary gearbox-v1.SLDASM](<solidworks/planetary gearbox-v1.SLDASM>) in SolidWorks. It contains **14 printed-part instances from eight part files**.

## How the parts fit together

- **Motor plate, ring gear and end plate:** form the stationary housing. The motor mounts to the motor plate; the output passes through the end plate.
- **Motor sun gear:** locks to the motor shaft with set screws and drives stage 1.
- **Stage 1:** three planet gears sit between a plain **carrier 1** and **carrier 2**. Their pins connect the two plates so they rotate together. Carrier 2's integral helical gear becomes the sun for stage 2.
- **Stage 2:** another three planets sit between a second **carrier 1** and **carrier 3**. Carrier 3's straight central teeth transmit the final output to a future matching coupling.
- **Planet support:** two NTN 685ZZ bearings per planet (**12 total**) run on smooth metal pins. Bearing fit, spacers and retention must be verified with the actual hardware.

## How it works

**Motor → sun → stage-1 planets/carriers → stage-2 sun → stage-2 planets/carriers → carrier-3 output.**

Each stage has a 15-tooth sun, 15-tooth planets and a fixed 45-tooth ring: `1 + 45/15 = 4:1`. Together they give **4 × 4 = 16:1**: sixteen motor turns produce one output turn in the same direction. Reduction increases available torque subject to losses and component strength.

The saved assembly is a **fixed static layout**. Hardware, central/output support, coupling and axial retention still need completion and testing; no load capacity is established. See the [full build plan](../../doc/BUILD_PLAN.md).
