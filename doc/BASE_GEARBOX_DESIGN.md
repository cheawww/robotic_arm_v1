# Current planetary gearbox layout



Updated **2026-10-29**. Dimensions below describe the saved CAD inspected in this conversation. Pending changes are explicitly identified. All dimensions are millimetres unless stated otherwise.



## Mechanical arrangement



The motor drives the separate sun gear. A fixed ring surrounds two stages of planets. Each stage has three planets between two carrier plates:

1. Stage 1 front: plain **carrier 1** inside the motor-plate cavity, outside the ring's axial span.
2. Stage 1 rear: **carrier 2**, whose integral helical gear is the stage-2 sun.
3. Stage 2 front: a second copy of **carrier 1**.
4. Stage 2 rear: a second copy of **carrier 2**, whose outward helical gear is the final output.

There is one separate motor sun, six planets, two carrier-1 parts and two carrier-2 parts. The carrier-2 integral gear is currently about 20 mm long; each planet gear is 10 mm wide. Do not replace the integral stage-2 sun with an extra independent sun or mistake carrier 1 for the final output.



## Saved dimensions



|Feature|Saved measurement|
|-|-:|
|Ring outside diameter / height|70 / 42|
|Ring internal tooth-tip cylinder|53.75 diameter|
|Carrier 1 and carrier-2 plate outside diameter|52|
|Each carrier plate thickness|5|
|Planet-pin pitch circle / radius|37.5 / 18.75|
|Planet-pin holes|Three 5 mm holes at 120 degrees|
|Carrier pin counterbores|10 mm diameter x 3 mm deep; 2 mm floor remaining|
|Carrier 1 centre opening|22 diameter|
|Carrier-2 current central cylindrical bore|Approximately 5.5 diameter; Hole Wizard feature label is not a verified bearing seat|
|Motor sun tooth width / added hub length|10 / 8; 18 total axial envelope|
|Motor sun measured shaft passage|Approximately 5.2 diameter|
|Planet tooth width / current bore|10 / 10 diameter|
|External sun/planet maximum diameter|21.25|
|Motor plate outside diameter / total axial envelope|70 / 15|
|Motor plate material at case fixing holes|5 axial thickness|
|Case fixing pitch circle|65 diameter, six holes|



The latest ring is **42 mm high**. Earlier conversations about 28, 30 or 40 mm were previous packaging ideas; they are not the current measured ring dimension. A simple sum of gear and plate thicknesses does not determine the housing length because recesses, overlaps and operating clearances matter.



## Axial stack



Assembly **Y** is the height/shaft axis. Y = 0 is the motor mounting face used in the existing assembly. Individual part files can use native Z as their extrusion axis.



|Item|Y start|Y end|
|-|-:|-:|
|Motor plate envelope|0|15|
|Stage-1 front carrier 1|10|15|
|Motor sun hub|7.5|15.5|
|Stage-1 sun teeth and planets|15.5|25.5|
|Stage-1 rear carrier-2 plate|26|31|
|Integral stage-2 sun|31|51|
|Stage-2 front carrier 1|35.5|40.5|
|Stage-2 planets|41|51|
|Stage-2 rear carrier-2 plate|51.5|56.5|
|Final integral helical output|56.5|About 76.5|
|Fixed ring|15|57|
|New end plate, proposed checked placement|57|67|



The user-measured motor shaft projection of about 25 mm ends 1 mm before the first rear carrier plate at Y = 26. This clearance depends on correct sun position and the actual motor-face datum; it is not a specification from an exact AEI datasheet.



## End plate



The saved end plate is 70 mm in diameter and 10 mm high. Its main 53 mm cavity has a 6 mm cut depth before chamfer effects; material at the fixing holes is 4 mm thick. Its centre opening is 23.25 mm.

At the checked placement, the open cavity faces inward, the mounting rim starts at Y = 57 and the cavity floor is at Y = 63. The output gear passes through the opening with **1 mm nominal radial clearance**. The main carrier plate ends at Y = 56.5 and does not collide with the cover. A three-part native SolidWorks fit check found zero overlaps.

The six end-plate hole centres match the ring exactly. The existing motor plate has a pre-existing case-pattern offset of up to approximately **0.154 mm**. Correct its pattern axis if bolts bind; do not move the end plate's correctly centred pattern to copy the offset.

At 70 mm outside diameter and 65 mm fixing PCD, a 3.4 mm hole leaves **0.8 mm outer ligament**. That is a thin printed edge. A tapped M3 thread in the ring leaves about 1 mm to the outer surface at the thread's nominal major diameter. Neither dimension establishes clamping strength.



## Pending revisions



Keep the ring height and internal gear geometry as the current baseline while developing the tapped fastening and 11 mm bearing seats. The direct-tapped case plan and all open support/retention details are described in [the fastener guide](SCREW_AND_FASTENER_GUIDE.md). No CAD change was made for this documentation update.



### Recommended R1 housing edit: proposal only



Increase the ring's outside diameter and the motor/end-plate **outer case flanges** from 70 to **74 mm**. Keep the gear tooth geometry, ring height 42 mm, case PCD 65 mm, carrier OD 52 mm, carrier thickness 5 mm, cavities and axial positions unchanged.



|Nominal outer material|Saved 70 mm OD|Proposed 74 mm OD|
|-|-:|-:|
|Ring at M3 thread major diameter|1.0 mm|3.0 mm|
|Plates at 3.4 mm clearance holes|0.8 mm|2.8 mm|



These are simple geometric ligaments, not allowable load calculations. The insert-free tapped arrangement still needs a physical strength test. If enlarging a flange, update every sketch/cut that defines its outer annulus, then rebuild and inspect the complete external envelope. This proposal does not mean that the saved 70 mm end plate has already been enlarged.



### Retention and load paths



The selected two 5 mm-wide bearings use the planet's whole 10 mm width. The first prototype seat is a through seat with its diameter set by the fit trial. Establish outer-ring retention and an inner-ring clamp stack separately; an extra integral bearing lip would require a different axial design. Plate counterbores must face outward so their remaining floors define the intended pin clamp stack.



Keep the carrier pairs square and connected by the three metal pins. Planet inner rings and appropriate spacers are clamped to those pins; the planet and its bearing outer rings rotate. Confirm the actual washers contact only the inner rings. Neither bearing shields nor gear faces are thrust washers.

For an arm joint, the final gear should mesh with a driven gear on a **separately supported joint shaft/hub**. The bracket's joint bearings carry link weight and moment. The gearbox output still needs a load path for the force of that mesh and any helical thrust. The downstream gear ratio is not yet chosen; the 16:1 value ends at carrier 2 and does not include that extra mesh.



### Axis naming



The table above uses **gearbox bench-assembly Y** along the motor shaft. When that gearbox is installed at a shoulder or elbow, align that local shaft axis with the joint's pitch axis; it need not remain the robot's vertical axis. The arm study uses X forward, Y up and Z lateral. Keep local and world coordinate frames explicit when adding kinematics or gravity calculations.

