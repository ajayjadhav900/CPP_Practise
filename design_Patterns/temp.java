Given the below CCF is fitted for "Seat" feature
|Parameter Name |Value|
| 0x1947        | 0x01| 
And the vehicle is in "FULL" state

When the "Seat TEMPERATURE enabled" screen is "shown" on "front centre" display
# Home > Footer Climate controls >Select "SEATS" tab

Then the following options are "not shown" on "front centre" display:
|Option Names|
|HSW control enabled|
# EMA Seats HMI Spec No Figma available

#clean up Start
And -cleanup the "outside drawer area" is selected on "front centre" display
#clean up Stop