# Current conclusion and remaining work

Updated **2026-10-29, integrated revision R1**. The practical next build is one complete bench gearbox, followed by a supported single-joint rig. The full arm is a design study, and this document does not certify a lifting capacity. [BUILD_PLAN.md](BUILD_PLAN.md) gives the fabrication and acceptance sequence.

## What is established

The planetary mechanism has two 4:1 stages and a **16:1 total reduction**. There are six planets and four carrier plates. Each stage uses one front carrier 1 and one rear carrier 2. The first carrier-2 integral gear drives stage 2; the second carrier-2 integral gear is the final helical output.

The native SolidWorks assembly was saved and reopened with 69 resolved components. Interactive rotation and a separate saved animation followed the expected gear and carrier speeds. This demonstrates constrained kinematic movement. Gear mates impose ratios; their operation is not proof of real tooth-contact forces or printed strength.

The user's new end plate is a valid single solid. Its six 3.4 mm holes match the ring's 65 mm pitch-circle pattern. A separate native check with the ring and final carrier 2 found zero solid overlaps at the proposed installation position. Its 23.25 mm opening provides 1 mm nominal radial clearance around the 21.25 mm output gear.

The user has physically printed an earlier set and reported that the parts remain meshed while moving, with a small amount of clearance. That is useful fit feedback; backlash, runout, retention and loaded operation remain unmeasured.

## Latest fastening decision

The user intends to fasten the motor plate and end plate **separately from opposite ends of the ring**, without separate case nuts. The active proposed revision is:

| Part | Proposed fixing detail |
|---|---|
| Ring gear | Six 2.5 mm pilot holes; cut M3 x 0.5 threads for 10 mm from each end |
| Motor plate, six case holes | Keep 3.4 mm clearance holes |
| End plate, six case holes | Keep 3.4 mm clearance holes |
| Case screws | Twelve M3x12 screws, six per end, no added washers in the length calculation |

A 2.5 mm hole is a **pilot for a cutting tap**. It is not a clearance hole or a finished thread. After printing, finish the pilot to size and use an M3 x 0.5 tap. Do not force a normal M3 screw into an untapped pilot. The saved ring still has 3.4 mm holes; no CAD change has been made. The earlier M3x55 through-bolt suggestion does not apply to this arrangement. See [the fastener guide](SCREW_AND_FASTENER_GUIDE.md).

## Work still required before an assembled running prototype

1. Revise and print the ring for the chosen fastening method, then test thread grip in the intended material. A printed 3.4 mm hole cannot be made smaller by tapping it.
2. Revise the six planet bores for the selected 685ZZ bearings. Their outside diameter is 11 mm; the current bores measure 10 mm. Establish the final printed fit with a small test piece.
3. Obtain suitable smooth metal planet pins and confirm nut, head and washer clearances. Do not use a printed stick as the assumed load-bearing axle.
4. Complete central sun support, output support and helical-thrust retention. The end plate currently provides clearance around the output gear, not a bearing seat.
5. Recheck the updated assembly after CAD revisions. The moving assembly uses isolated GBX_ copies and will not automatically receive edits to the original models.

The cover's thin outer hole ligaments and the motor plate's small pattern offset also need a physical fastening check. Details are in [the gearbox layout](BASE_GEARBOX_DESIGN.md).

## Recommended R1 mechanical package

The next CAD revision should retain the 42 mm ring height and the existing gear, carrier and shaft-axis positions. Increase the outside diameter of the ring and the matching case flanges to **74 mm**, leaving the six fixing-hole centres on the existing 65 mm PCD. This increases the outer material beyond an M3 ring thread from approximately 1 to 3 mm and beyond a 3.4 mm plate hole from 0.8 to 2.8 mm. Update all relevant outer annular-cut boundaries as well as the outer extrusion; merely editing one circle can leave an unwanted rim. The 74 mm revision is proposed and has not been checked in CAD.

Keep the user's two-ended short-screw arrangement for this prototype, with physical tapping after printing. Select the bearing seat from a coupon trial, prove one complete planet and pin stack, then manufacture the remaining five. Do not assume that the 5 mm bearing width leaves room for a 1 mm internal retaining lip inside a 10 mm gear containing two bearings.

For the robot arm, support each loaded joint with a shaft/hub and a suitable spaced bearing arrangement in the joint bracket. The gearbox transfers drive torque; the joint structure carries link weight and overturning moment. The final helical output also produces mesh forces, so separate joint bearings do not remove the need for gearbox output support and thrust retention. The current end plate is only a clearance cover.

Keep the archived U-bracket, gusset, hollow-link and staged-assembly ideas. Do not reinstate its incompatible 5:1 base gearbox, 650 mm reach, assumed NEMA 23 purchase, exact servo choices or 1-2 kg payload claims. Joint actuation remains conditional on measured running torque and the real arm mass budget.

## Robot-arm performance

The target reach is **500 mm horizontally**. A 500 g payload alone produces **2.452 N.m** at the shoulder when held 500 mm away. A fresh, explicitly assumed arm-mass example produces **4.748 N.m** shoulder gravity torque and **2.116 N.m** elbow gravity torque. These are calculation examples, not measured arm requirements.

The exact motor running torque, complete arm masses, structural stiffness and gearbox load capacity are unknown. Therefore neither 16:1 planetary nor a 20:1 belt/planetary combination can currently be promised to lift 500 g. See [the calculations](stability_analysis.md).

Using the current illustrative mass budget, multiplier 2 and assumed efficiencies, the motor would need approximately **0.822 N.m for the shoulder at 16:1**, **0.588 N.m at 20:1**, or **0.173 N.m at 80:1**, at the corresponding operating speed. These are required motor torques, not measured capabilities. Use the matching speed and torque curve to select a drive; the reduction alone is insufficient evidence.
