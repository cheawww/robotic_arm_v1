# SolidWorks files and current bill of materials

Updated **2026-10-29**. Original files and generated assembly copies are separate. This documentation revision does not edit either set.

## Original models

Source directory:

`E:\PROJECT\project_robot_arm\model\plenetary gear box\solidworks`

| Original file | Current saved geometry / role |
|---|---|
| `sun gear.SLDPRT` | Motor input; 15 teeth, 10 mm tooth width, 8 mm added hub, about 18 mm total axial extent; measured passage about 5.2 mm |
| `plenetary gear.SLDPRT` | 15 teeth, 10 mm width, 21.25 mm maximum diameter, current 10 mm bore |
| `ring gear.SLDPRT` | 45 internal teeth, 70 mm outside diameter, 42 mm height, six 3.4 mm case holes on 65 mm PCD |
| `gear carrier.SLDPRT` | 52 mm outside diameter, 5 mm thick, 22 mm centre opening, three 5 mm pin holes on 37.5 mm PCD |
| `gear carrier-2.SLDPRT` | 52 mm x 5 mm carrier plate with approximately 20 mm integral helical gear; central cylindrical passage in the gear portion about 5.5 mm |
| `motor plate.SLDPRT` | 70 mm outside diameter, 15 mm total envelope; 5 mm material at case holes and separate motor mounting features |
| `end plate.SLDPRT` | 70 mm outside diameter, 10 mm height, 53 mm main cavity, 23.25 mm output passage, six 3.4 mm case holes |

All seven source hashes still match the 2026-10-29 read-only audit. All seven were valid single solid bodies with no reported feature warnings/errors. No claim is made that they already contain the proposed new holes or bearing seats.

## Main native assembly and animation

The existing generated CAD remains in its original directory to protect references:

`E:\PROJECT\project_robot_arm\output\solidworks_assembly_20261019\Four_Carrier_Gearbox`

| File | Use |
|---|---|
| `Planetary_16to1_Assembly.SLDASM` | Main editable assembly and interactive constrained rotation |
| `Planetary_16to1_MotionVerified.SLDASM` | Separate saved native animation; study `16_to_1_Gearbox_Demo` |
| `GBX_*.SLDPRT` | Isolated component copies used by those assemblies |

The main assembly has 69 instances and 16 unique part files. It contains four carrier plates and six planets. Its older reference hardware includes M3x50 through-screws and M3 nuts; the latest two-ended M3x12 fastening proposal is not implemented there. The end plate is not included in this moving assembly.

The animation is a calculated two-second demonstration. At its end, input / first carrier / final carrier rotate approximately 114.5916 / 28.6479 / 7.1620 degrees, respectively. Input speed is about 9.55 rpm for visibility. Nine saved time positions and interactive movement were verified; this was not a torque/contact-force simulation.

Editing the originals does **not** automatically update the GBX_ copies. After future CAD changes, deliberately synchronize the required copies and recheck mates, references, interference and movement. Do not casually rename or move linked native files.

## End-plate check assembly

`E:\PROJECT\project_robot_arm\non-me\end_plate_review_20261029\End_Plate_Fit_Check.SLDASM`

This is a three-component **fixed, static fit-check assembly** referencing the original end plate, ring and final carrier 2. At the checked placement it rebuilt, saved and had zero detected solid overlaps. It is not the complete moving gearbox.

## Proposed physical bill of materials

| Item | Quantity | Current status |
|---|---:|---|
| Motor plate / ring / motor sun / end plate | 1 each | End plate checked separately; receiving ring threads pending |
| Planet gears | 6 | Bore revision for 11 mm bearing OD pending |
| Carrier 1 / carrier 2 | 2 each | Four carrier plates total; each plate is 5 mm thick |
| 685ZZ bearings, 5 x 11 x 5 mm | 12 | Selected for planets; two per planet |
| Custom smooth planet pins, 5 mm seat, 19 mm under head | 6 | 15 mm smooth plus 4 mm M5 thread; exact supplier match unverified |
| Thin M5 nuts | 6 | Reference 8 mm AF x 2.7 mm thick; verify purchased parts |
| Inner-ring washers, 5.2 / 6.5 / 0.5 mm | 12 | Trial dimensions; contact against actual bearing inner ring must be checked |
| M3x12 case screws | 12 | Proposed direct-tapped ring arrangement; six per end, no separate case nuts |
| M3 motor mounting screws | 4 | M3x8 nominal reference; confirm actual motor engagement |
| Motor-sun set screws | 2 references | Nominal M2.5; exact length and thread/shaft engagement need confirmation |
| Central sun support and output support/retention | Not finalized | No completed bearing/hub arrangement to purchase from this list |

No new total assembly-instance count is claimed for this pending physical configuration. Reference bearings, fasteners and motor solids in the old assembly simplify real hardware details.

## Reports, website and other generated files

The generated non-native files were moved into `E:\PROJECT\project_robot_arm\non-me` on 2026-10-29. The 416 moved files no longer remain at their old locations; all 61 pre-existing native SolidWorks files kept their paths and contents during that organization.

- Main assembly report and verification JSON: `../non-me/output/solidworks_assembly_20261019/Four_Carrier_Gearbox/`.
- End-plate report and audit data: `../non-me/end_plate_review_20261029/`.
- Website: `../non-me/visualizer/index.html`.
- Portable gearbox ZIP: `../non-me/output/solidworks_assembly_20261019/Planetary_16to1_Complete_Portable.zip`.

The website and portable ZIP are earlier snapshots. They are not automatically updated by this document rewrite or by future original-part edits. Prefer this document set for the latest fastening intent and pending-work status.

## Future R1 changes are a separate drawing revision

The recommended next housing revision increases the ring and both outer case flanges to **74 mm OD**, with unchanged 42 mm ring height, 65 mm fixing PCD and internal gear geometry. The planet bearings, tapped ring holes, output support and motor-pattern correction are also pending. None of these proposals should be mistaken for geometry in the saved source parts or GBX_ copies.

Assign a revision to changed printed parts and regenerate their print exports. Check that both matching plates and all six planets use the intended revision; do not mix a 10 mm bore export with an 11 mm bearing-seat drawing. The earlier STL files under `model/plenetary gear box/print...` are not automatically current when the source CAD changes.

## Arm modules to model after the gearbox test

| New module group | Purpose | Existing verified native arm CAD? |
|---|---|---|
| A01 rigid base and enclosure mounts | Transfer joint reactions to a workbench; hold electronics separately | No |
| A02 supported yaw hub | Carry arm weight/moment and accept yaw-drive torque | No |
| A03 shoulder fork, shaft and adapters | Double-sided support and drive/counterbalance connection | No |
| A04 upper-arm link | Working 220 mm joint-centre spacing, with cable route | No |
| A05 elbow fork, shaft and adapters | Support the forearm and connect its drive | No |
| A06 forearm link | Working 200 mm elbow-to-wrist spacing | No |
| A07 roll/wrist/tool assembly | Package roll, wrist and gripper within the working 80 mm distal allocation | No |
| A08 cable guides, stops and optional counterbalance brackets | Limit travel and provide a controlled load path | No |

These are module groups, not eight ready-to-print parts or a complete new BOM. Do not reinstate the archive's contradictory 27/30/31 unique-part and 33-print totals. Count actual released native files and assembly instances once the arm is designed.

For procurement, the planet pins, washer contact geometry, motor-sun fixation and output support are fabrication/selection tasks, not an already verified shopping bundle. Record supplier, exact part number, dimensions, quantity, received measurements and price before treating an item as acquired. No historical Thai price is carried forward as a current quotation.
