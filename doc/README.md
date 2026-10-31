# Current robot-arm and planetary-gearbox documents

Updated **2026-10-29, integrated revision R1**. The current documents are in `E:\PROJECT\project_robot_arm\doc`. The eight archived design documents have now been reviewed following the user's latest request. Useful assembly and load-path ideas are incorporated; incompatible dimensions, unsupported performance claims and obsolete motor selections are not adopted. See [the reconciliation](DESIGN_RECONCILIATION.md).

**This is a documentation revision only. No CAD or assembly file was edited.** A proposed change in these documents is not evidence that the corresponding saved model has been changed.

## Current project baseline

| Item | Current position |
|---|---|
| Arm reach | 500 mm maximum horizontal shoulder-to-gripper reach |
| Payload | Discussed 500 g target; no verified working-load rating |
| Motor | User's AEI.th NEMA 17 42BYGH40, lot 032025; exact electrical rating and torque-speed curve unconfirmed |
| Motor shaft projection | Approximately 25 mm, measured by the user |
| Gearbox | Two fixed-ring planetary stages, 4:1 each, 16:1 total |
| Teeth per stage | 15 sun / 15 each planet / 45 ring; three planets per stage |
| Carriers | Two plates per stage: carrier 1 and carrier 2; four plates total |
| Current ring | 70 mm outside diameter, 42 mm axial height |
| Carrier plates | 52 mm outside diameter, 5 mm plate thickness |
| Planet bearings selected | Two 685ZZ bearings per planet, twelve total, nominal 5 x 11 x 5 mm each |
| Latest case-fastening intent | Short screws from both ends into the ring, without separate case nuts |
| Pending fastening proposal | Ring pilot holes 2.5 mm, tapped M3 x 0.5 for 10 mm from each end; twelve M3x12 screws; plate clearance holes remain 3.4 mm |

## Read by task

- [Build plan: decisions, CAD revisions, fabrication and test order](BUILD_PLAN.md)
- [Current conclusion and remaining work](FINAL_CONCLUSION.md)
- [Gearbox layout, dimensions and axial stack](BASE_GEARBOX_DESIGN.md)
- [Gear ratios and carrier geometry](PLANETARY_4_TO_1_AND_16_TO_1_DESIGN.md)
- [Hole sizes, screws, bearings and retention](SCREW_AND_FASTENER_GUIDE.md)
- [CAD files, quantities and verified assembly status](solidworks_parts_list.md)
- [What the parts do and what the payload target means](PART_APPEARANCE_AND_PAYLOAD_GUIDE.md)
- [Arm architecture and motor information](robotic_arm_design.md)
- [Fresh torque calculations and stability limits](stability_analysis.md)
- [Machine-readable inputs and calculation results](current_calculations.json)
- [What was kept, corrected or rejected from the archive](DESIGN_RECONCILIATION.md)

## How to use the set

Start with a complete **bench gearbox prototype**, then a supported single-joint rig, then the arm. Keep the measured 16:1 mechanism as the first test article; do not buy five complete joint drives on the strength of the animation. Use the build plan's stages to decide what is ready for fabrication and what still needs an actual hardware measurement.

The recommended **future R1 housing proposal** keeps the 42 mm ring height, existing teeth, 65 mm case PCD and 5 mm carrier plates. It increases the ring, motor-plate flange and end-plate flange outside diameter to **74 mm** to improve the thin material outside the fixing holes. This is an engineering proposal, not a saved-CAD measurement or a completed strength validation. Case screws remain twelve M3x12 entering tapped ring ends. Full instructions and remaining interfaces are in [BUILD_PLAN.md](BUILD_PLAN.md).

The arm concept uses 500 mm horizontal reach. A 220 / 200 / 80 mm allocation is the **working study layout**, not a claim that all arm parts already exist. A 350 x 260 mm base is a **layout example** recovered from the archive and recalculated with the new mass example; it has no approved payload rating.

## Saved CAD versus pending revisions

The latest verified source files still contain **3.4 mm ring fixing holes** and **10 mm planet bores**. They have not yet received the proposed tapped-hole revision or seats for 11 mm bearing outside diameters. The end plate was checked separately and has not been added to the original moving gearbox assembly. Output bearing support, helical-thrust retention, and central sun support remain unfinished.

The 69-component native gearbox assembly and its separate saved animation demonstrate the 16:1 movement. They do not establish gear strength, continuous tooth-contact quality, motor torque capacity, or robot-arm payload capacity.

## Evidence used

- Native seven-part geometry audit: `../non-me/end_plate_review_20261029/native-audit.json`.
- End-plate static fit check: `../non-me/end_plate_review_20261029/native-fit-check.json`.
- Original-file preservation: `../non-me/end_plate_review_20261029/source-hashes-before.json`; all seven current source hashes still match.
- Previously verified native movement: `../non-me/output/solidworks_assembly_20261019/Four_Carrier_Gearbox/verification.json`.
- Fresh recomputation script: `../non-me/document_refresh_20261029/recalculate.py`.

The previous documents remain preserved in `../non-me/archived_old_documents_20261029/`. They were unread during the first rewrite and reviewed during this integration. The working copy immediately before this integration is in `../non-me/document_integration_20261029/before/`. The archive is a source of reviewed ideas, not authority over the current conversation or measured CAD.
