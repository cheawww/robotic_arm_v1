# Build plan: gearbox prototype to robot arm



**Revision R1, 2026-10-29. Documentation only: no CAD files were changed.** This is a fabrication and verification sequence, not a claim that a complete arm drawing set has been released.



## 1\. Freeze the first test article



Build one two-stage **16:1 gearbox** first, using the user's AEI NEMA 17. Keep the existing 15/15/45 teeth, three planets per stage, four 5 mm carrier plates, 37.5 mm pin PCD and 42 mm ring height. The final output is carrier 2. The later driven joint gear and any belt stage are separate design decisions.

The bench objective is repeatable motion, controlled bearing/shaft location and secure retention. The arm objective remains 500 mm horizontal reach and a discussed 500 g payload target; it is not the first bench-test acceptance load.



## 2\. Prepare the next CAD revision later



The following is the recommended **R1 proposal**, to be applied when the user resumes CAD work:



|Item|Saved model|R1 drawing instruction|
|-|-|-|
|Ring|OD 70, height 42, six 3.4 mm case holes|Propose OD **74**; keep height and internal teeth; change fixing pilots to **2.5 mm** and cut **M3 x 0.5** threads for **10 mm usable depth from each end**|
|Motor plate|OD 70, total envelope 15, case flange 5 thick|Propose outer flange OD **74**; retain cavity/axial placement; keep six **3.4 mm** case clearances; centre their pattern on the main axis|
|End plate|OD 70, total height 10, case flange 4 thick|Propose outer flange OD **74**; keep 53 mm main cavity and 23.25 mm output passage; retain six **3.4 mm** case clearances|
|Planet gears|Bore 10, width 10|Design a full-width seat for **two 685ZZ 5 x 11 x 5 mm bearings**; select final diameter from the print-fit trial|
|Carrier plates|OD 52, thickness 5, pin PCD 37.5|Preserve these datums and outward-facing 10 x 3 mm counterbores; confirm purchased pins/nuts/washers first|
|Motor sun|10 mm teeth plus 8 mm hub|Confirm measured shaft fit, flat and set-screw thread/length; preserve its checked axial position|
|Support/retention|Central and output details unfinished|Complete the shaft/hub/bearing and thrust-retainer drawings before powered or loaded operation|



The proposed 74 mm OD increases the outer ligament to 3 mm beside an M3 ring thread and 2.8 mm beside a plate clearance hole. It does not prove strength. Update the associated annular outer-cut boundaries, not just one extrusion circle. Keep the 65 mm case PCD and all internal gear surfaces unchanged. Recheck mating flanges and the external envelope after rebuilding.

The saved end-plate fit check is for the **70 mm** part. The proposed 74 mm revision has not been inspected in SolidWorks. Do not claim that a cosmetic tapped-hole annotation creates printable thread grooves.



## 3\. Purchase or fabricate the critical interfaces first



|Hardware|Needed for one gearbox|Readiness requirement|
|-|-:|-|
|685ZZ bearings|12|Measure the received samples; two per planet|
|Custom smooth planet pins|6|Drawing: 5 mm smooth diameter, 15 mm smooth length, 4 mm M5 x 0.8 thread, 19 mm under-head length, head envelope 9.5 x 2.75 mm|
|Thin M5 nuts|6|Verify about 8 mm AF and 2.7 mm thickness against 10 x 3 mm recesses|
|Inner-ring spacers/washers|12|About 0.5 mm thick; final OD must contact only the actual inner rings; existing 6.5 mm OD reference is unapproved|
|Case screws|12 M3x12|Socket/button-head length measured under the head; six per end; no extra washers in the current length calculation|
|Motor fixing screws|4 M3, nominal M3x8 reference|Confirm real motor thread depth and mounting thickness|
|Motor-sun set screws|2 reference positions|Confirm actual thread, length and shaft-flat engagement|
|M3 x 0.5 cutting tap and 2.5 mm drill|Tools|Required for the direct-tapped ring method|



The six pins are a **machining task**, not a verified standard shopping item. Obtain a quote/sample or redesign around a fully specified commercial shoulder pin. Do not silently replace the drawing with an ordinary fully threaded M5 screw. If the replacement shoulder/thread/head changes, revise its carrier detail before final printing.

The no-case-nut plan removes separate M3 case nuts. It does not remove the M5 retaining nuts on the planet pins.



## 4\. Print small interface trials



Use the actual material, nozzle, orientation and printer profile intended for the final parts. The user has PLA/PETG and a Bambu Lab P2S; nozzle diameter has not been confirmed.

For bearing-seat trials, a candidate CAD-diameter sweep is **10.90, 10.95, 11.00, 11.05 and 11.10 mm** in 10 mm-thick test samples. These are test candidates, not universal production tolerances. Measure holes, insertion force, cracking and looseness with the purchased bearings. Then prove the selected seat in one complete planet, because a simple coupon may have different wall stiffness. An 11.05 mm drawing does not automatically imply a press fit.



The two nominal 5 mm bearing widths already occupy the 10 mm gear width. Do not add an internal 1 mm retaining lip or 2 mm middle spacer without redesigning the width and stack. Select outer-ring retention separately from the inner-ring clamp stack.



Make a representative tapped-hole trial before committing to the ring. Finish the pilot to 2.5 mm, tap M3 x 0.5, and test the intended screw and engagement. A printed hole that is already 3.4 mm cannot be reduced by tapping. Establish acceptable tightening and repeated-use behaviour from the material trial; no tightening-torque rating is assigned here.

Use the printer/material profile as a starting point and inspect the sliced teeth and carrier floors. Ensure adequate local solid material and continuous walls at teeth, pin holes and case threads. Do not assume a particular perimeter count guarantees solid teeth. Control elephant foot, support scars and fit independently; do not globally scale the assembly to fix one tight bearing hole.



## 5\. Hand-fit the complete mechanism



1. Confirm the measured motor interface and shaft projection. Fix the sun at the intended axial location; verify set-screw access and shaft-flat contact.
2. Assemble one planet with two bearings, correct inner-ring washers, the two carrier floors and one metal pin/nut. It must rotate after the inner stack is secured. Correct this before assembling the remaining five.
3. Install all three stage-1 planets and both stage-1 plates. The front carrier 1 lies in the motor-plate cavity. Verify tooth phase and rotation.
4. Use stage-1 carrier 2's integral gear as the second sun. Install the second carrier pair and all three stage-2 planets. Carrier 2 is the final output.
5. Fit the stationary ring and end plate, retaining the axial stack in [BASE\_GEARBOX\_DESIGN.md](BASE_GEARBOX_DESIGN.md). Use six M3x12 screws from each end into the completed ring threads, tightening evenly.
6. Rotate slowly by hand through multiple input turns in both directions. Record tight spots, axial rubbing, retention, backlash and whether any planet or bearing shifts.

Hand rotation is a fit check. Before powered operation, finish central/output radial support and axial retention so the mechanism cannot rely on loose gear contact or a bearing shield as a locating surface.



## 6\. CAD and bench acceptance records



|Stage|Required evidence before proceeding|
|-|-|
|Drawing revision|Each changed native part has a revision, material/print assumptions and actual hardware dimensions; matching exports regenerated|
|Updated CAD assembly|All references resolve; no unintended solid overlaps; intentional bearing-seat fits distinguished from clashes; motion and tooth phase rechecked|
|Hand-fit mechanism|All six planets present; four carrier plates; no binding, shield clamping or uncontrolled axial movement; 16 input turns give one output turn|
|Supported powered bench test|Driver current settings tied to verified motor data; correct direction; low-speed unloaded travel and stopping demonstrated; backlash, temperature and lost steps recorded|
|Single-joint rig|Joint shaft/bearings and external driven gear carry their actual loads; controlled load-loss restraint and measured torque-versus-speed test|
|Arm extension|Actual mass/COM data replace the study budget; torque and support-polygon calculations repeated for real poses; loads increased only within demonstrated capability|



Record part revision, material/nozzle/profile, bearing/pin part numbers, measured fits, input/output angles, free output movement, test load and lever arm, speed, driver setting, test duration and observations. A pass should be repeatable in both directions. Manufacturer motor/driver limits determine permitted settings; this plan does not invent electrical or thermal ratings.



## 7\. Build the arm in useful increments



Use a rigid, properly attached workbench platform for development; keep its structural load path separate from a printed electronics cover. Add a supported yaw hub, a supported shoulder rig and the upper arm before adding the elbow, forearm, wrist and tool. If a drive cannot hold the measured load with the required operating allowance, change reduction, reduce distal mass/reach, add a calculated counterbalance or choose another motor before extending the arm.



Keep the 220 / 200 / 80 mm allocation as a planning model until actual joint envelopes fit. Do not add the archived roll and gripper lengths outside the 80 mm distal allowance. Do not duplicate forearm roll as an extra axis without adding its mass, wiring and reach.



At a loaded joint, bracket bearings carry structural loads while the drive transmits torque. The helical output mesh still loads the gearbox's output support. Choose that support, the driven gear and joint shaft together; an arbitrary output bearing cannot be pressed over gear teeth. Start with the support architecture in [robotic\_arm\_design.md](robotic_arm_design.md), then use the operating-point calculations in [stability\_analysis.md](stability_analysis.md).



No CAD, firmware, live motor setting or hardware was changed by writing this plan. The completed artifact here is the coordinated document set; the fabrication stages above remain future work.

