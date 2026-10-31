# Review of archived designs and current decisions

**2026-10-29, integrated revision R1.** The user requested that the documents previously replaced now be read, considered and applied to the current set. All eight archived Markdown documents and their four metadata files were reviewed, together with all current documents and calculation/metadata files. The archived files themselves were preserved.

## Source priority

Use the user's latest requirements, measured current CAD/hardware and explicitly stated new calculations to resolve conflicts. Older documents supply ideas to evaluate, not proof that a part exists or a motor/load rating has been established. Verified CAD and pending R1 proposals are separate.

| Archived idea or claim | Treatment in the current set | Reason |
|---|---|---|
| Modular base, turntable, forks, hollow links, wrist and tool | Retain as module concepts | Useful practical structure; sizes must follow real interfaces |
| Separate joint bearings and gearbox drive | Retain and clarify | Structural arm loads need a bracket/shaft support path; gear-mesh and thrust loads still act on the gearbox |
| Sequential assembly and one-joint testing | Retain as explicit build stages | Makes failures observable before distal mass is added |
| Rear placement of heavy components and ballast | Retain as a parameterized balance option | Requires actual mass/location; a PSU name is not a balancing mass |
| 350 x 260 mm base footprint | Retain as a clearly labelled layout example | Recalculate with the current mass example; check lateral/yaw stability too |
| Fixed 75 cm height and 650 mm reach | Supersede with 500 mm horizontal reach | Latest user requirement; previous link/module budgets conflicted |
| Base 5:1 gearbox with 12/18/48 teeth | Do not apply to the current CAD | Existing two-stage mechanism is 15/15/45, 4:1 per stage and 16:1 total |
| A second sun extruded on carrier 1 | Correct to carrier 2 | The actual stage-1 rear carrier-2 integral gear drives stage 2 |
| One 685ZZ per planet | Supersede with two per planet | User selected two 5 mm-wide bearings to fill 10 mm planet width |
| 11.05 mm always gives a bearing press fit | Replace with fit trials | Actual print process and received bearing determine fit |
| Extra 1 mm bearing lip with two 5 mm bearings in a 10 mm gear | Do not combine those dimensions | Nominal widths already total 10 mm |
| 6804 bearing fits a 22 mm pocket | Correct envelope to 20 x 32 x 7 mm | Manufacturer dimensions; no particular output bearing is yet selected |
| NEMA 23 is always required; named servos automatically suffice | Remove categorical selections | Need actual torque-speed, offsets, driver limits and geometry |
| Holding torque multiplied by ratio proves 500 g payload | Reject as performance evidence | Running torque and structure are unverified |
| Anchoring guarantees 1-2 kg capacity | Reject | Anchors address base reactions, not every component's capacity |
| Extending only the rear footprint fixes forward tipping | Correct | It does not advance the front support edge |
| Roll torque is always zero | Correct | Pose, eccentric tool mass, acceleration and friction matter |
| Fixed M4x55 housing ties | Supersede | User wants twelve short M3x12 screws into tapped ring ends |
| One generic clearance/pilot size or insert hole for every screw | Replace with functional hole specifications | Clearance, tap pilot, locating bore and supplier-specific insert seat are different features |
| 27 unique parts / 33 prints | Do not carry forward | Archived lists and counts disagreed; future arm modules have no released CAD/BOM |
| Fixed electronics/software versions and Thai prices | Keep only the architecture idea | Final hardware, software compatibility, power budget and current quotes are not established |
| Print settings guarantee solid teeth or a fixed percentage wear reduction | Remove guarantees | Inspect slicing and test actual material/geometry/lubricant compatibility |

## Coordinated R1 recommendations

Keep the current gear teeth, 42 mm ring height, 5 mm carrier plates and four-carrier layout. Propose a 74 mm outer housing/flange diameter with the existing 65 mm case PCD to improve the thin outer ligaments. Retain the user's two-ended tapped M3 arrangement, verify its printed strength, trial the 685ZZ seats and prove one complete metal-pin stack. Complete central/output support and thrust retention before powered/load tests.

R1 is a **documented proposal, not a CAD revision already performed**. The old moving assembly still uses its isolated original GBX_ parts and older reference fasteners. The new end plate remains in a separate static check assembly.

## Meaning of the recalculated numbers

The 4.748 N.m shoulder / 2.116 N.m elbow values use stated assumed component masses and a 220 / 200 / 80 mm study layout. They are not lifted from the archived mass budgets and are not measurements. Required motor torque, base COM examples, outer-ligament dimensions and helical mesh-force examples are recalculated from their stated inputs in `current_calculations.json`.

The useful outcome is a consistent prototype build sequence with specific drawing/measurement tasks. A working payload rating still requires actual drive data, complete support details and reproducible tests. Writing consistent documents does not perform those physical tests.

## Files and preservation

The active documents are in `E:\PROJECT\project_robot_arm\doc`. Prior `doc_old_dont_read` paths are historical and should not be recreated. The immediate pre-integration set is preserved under `../non-me/document_integration_20261029/before/`. Original source CAD and existing assemblies were not edited or moved during this integration.
