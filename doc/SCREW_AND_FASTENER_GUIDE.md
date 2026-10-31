# Current screws, holes, bearings and retention

Updated **2026-10-29**. The active case-fastening intent is short screws entering the ring from both ends, without separate case nuts. The CAD modifications below are **pending**, not already performed.

## Case fastening: direct-tapped prototype proposal

| Location | Saved CAD | Proposed change |
|---|---|---|
| Six ring fixing holes | 3.4 mm clearance holes | 2.5 mm pilot holes, cut M3 x 0.5 threads for 10 mm from each end |
| Six motor-plate case holes | 3.4 mm | Keep 3.4 mm clearance |
| Six end-plate holes | 3.4 mm | Keep 3.4 mm clearance |
| Case fasteners | Older assembly contains six M3x50 screws and six M3 nuts | Twelve M3x12 screws, six per end; separate case nuts are not used in this proposal |

**2.5 mm is a tap-drill/pilot diameter.** After printing, finish the pilot to size and use a cutting tap for M3 x 0.5. The tap cuts the female thread grooves. A plain 2.5 mm hole is not a finished threaded hole, and an ordinary M3 machine screw is not an assumed self-tapping screw. See the [Guehring cutting-tap chart](https://guhring.com/media/catalogs/lgbkp3ieki4.pdf), M3 x 0.50 row.

In SolidWorks, specify an M3 x 0.5 tapped-hole detail rather than describing the receiving hole as an M3 clearance hole. A cosmetic thread annotation does not print physical grooves; this proposal relies on tapping after printing.

With socket/button-head screw length measured under the head and no additional washers:

- Motor-side engagement: `12 - 5 mm flange = 7 mm` into the ring.
- End-plate-side engagement: `12 - 4 mm flange = 8 mm` into the ring.
- Proposed complete usable threads: 10 mm from each ring end. Confirm actual tap lead, thread depth and screw seating.

The ring is 42 mm long, so the opposed screws do not meet. If making blind pilot holes instead of a continuous smaller pilot, allow extra depth for the drill tip and tap lead; do not make the screw bottom out.

An already printed 3.4 mm ring hole cannot be shrunk to 2.5 mm by tapping it. Reprint the changed ring or redesign its retention method. The earlier M3x55 through-bolt suggestion belongs to a different fastening arrangement and is not required here.

This direct-plastic-thread arrangement is a prototype proposal. Its pull-out resistance, tightening torque and repeated-use durability are unverified. Test in the actual printed material. Brass inserts are a possible later revision, but need their own specified pilot diameters and enough surrounding material; do not simply enlarge the existing near-edge holes for an unspecified insert.

For the recommended future R1 housing proposal, increase the ring and matching outer case flanges to **74 mm OD**, retaining the 65 mm PCD and the M3x12 length calculations above. This improves the outer ligament while preserving the gear stack. Correct the motor-plate circular-pattern axis to the main case axis. These changes are pending; no CAD file has been modified.

## Do not resize every hole to the screw's nominal diameter

| Purpose | Appropriate treatment in this project |
|---|---|
| M3 screw passing through a plate | 3.4 mm nominal clearance, then verify the printed fit |
| Receiving M3 x 0.5 thread | 2.5 mm finished pilot, then cut threads |
| Precise planet-pin location | Nominal 5 mm smooth axle and the saved 5 mm carrier holes; establish the real fit separately |
| Bearing outside-diameter seat | Match the purchased bearing and a print-fit test; unrelated to screw clearance |

The 5 mm carrier holes position the planet axes. They are not a request to change every M5 clearance hole in the project to 5 mm.

## Planet bearings

Use **two 685ZZ bearings per planet**, twelve total for six planets. Nominal dimensions are **5 mm bore x 11 mm outside x 5 mm width**, as listed by [NSK](https://www.nsk.com/engineering/products/bearings/ball-bearings/deep-groove-ball-bearings/extra-small-ball-bearings-and-miniature-ball-bearings-metric-series/685zz-esm-md.html).

Two widths add to 10 mm, matching a planet's width. Do not add the previously discussed 2 mm middle spacer to that 10 mm stack. The current 10 mm planet bores **do not fit an 11 mm bearing OD**. The bearing seats must be redesigned; no universal final CAD allowance is specified until a printed fit sample is tested.

These twelve bearings cover the planets only. The proposed central sun-support bearing and output support have no completed seat/retention arrangement.

## Planet pins and nuts

The existing assembly uses six **custom metal pins** with these reference dimensions:

| Detail | Nominal dimension |
|---|---:|
| Smooth axle diameter | 5 mm |
| Smooth length | 15 mm |
| Final thread | M5 x 0.8, 4 mm long |
| Total under-head length | 19 mm |
| Head envelope | 9.5 mm diameter x 2.75 mm high |
| Retaining nut | M5 thin nut, 8 mm across flats x about 2.7 mm thick |
| Carrier head/nut counterbores | 10 mm diameter x 3 mm deep |

An ordinary fully threaded M5 screw does not reproduce the smooth bearing seat. No exact marketplace match for these custom pins has been established. Confirm the supplied pin and nut dimensions before printing final pockets.

Each 5 mm plate with a 3 mm recess has a 2 mm floor. The nominal clamp stack is `2 + 0.5 + 10 + 0.5 + 2 = 15 mm`, including two 0.5 mm inner-ring washers per planet. The 4 mm threaded end extends beyond this stack. This is dimensional bookkeeping, not a fastener-strength rating.

The twelve proposed washers are ID 5.2 / OD 6.5 / thickness 0.5 mm. **Their outside diameter is not yet approved against the purchased bearing's inner-ring face.** They must not press on shields or rotating outer rings. Tightening should clamp the appropriate stationary inner-ring stack without stopping planet rotation.

The no-case-nut decision does not remove these six M5 planet-pin retaining nuts.

### Prove one complete pin stack before ordering six

The custom 19 mm pin specification is a fabrication drawing requirement, not a verified off-the-shelf screw designation. Give a machinist the smooth diameter, 15 mm shoulder length, 4 mm thread, head dimensions and purchased bearing sample. Confirm shoulder/thread runout so the nut reaches its clamping position without bearing on an unfinished shoulder.

For one trial planet, install two bearings, the correct inner-ring washers, both carrier floors and the nut. Tighten to secure the inner-ring stack and check that the planet still turns freely. A washer marked for M5 is not automatically suitable for a miniature bearing: its outside diameter may contact the shield. Do not order all the printed pockets around an unmeasured washer or substitute fully threaded M5 screw surfaces under the bearings.

If only a different commercial shoulder pin is available, its thread, grip length, head and nut may require a revised carrier detail. Treat that as a coordinated drawing change rather than assuming any part labelled M5x20 is equivalent.

## Motor and sun fixing

- Four **M3 motor mounting screws** are separate from the twelve case screws. M3x8 is the existing nominal reference; check actual AEI motor thread depth and plate thickness before installation.
- The motor sun is intended to lock to the shaft with **set screws**. The reference assembly contains two nominal M2.5 set-screw bodies. Exact length, thread pitch, shaft-flat engagement and printed-hub thread strength still need checking.
- Hole Wizard feature names such as "M6 Tapped Hole" are not proof of the actual bore or a correctly manufactured thread. Use measured geometry and the actual thread specification.
