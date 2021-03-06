$OpenBSD$
--- src/Cocoa/JoystickHandler.h	Sat Mar  6 18:11:04 2021
+++ src/Cocoa/JoystickHandler.h	Sat Mar  6 18:20:16 2021
@@ -66,7 +66,7 @@
   AXIS_VIEWX,
   AXIS_VIEWY,
   AXIS_end
-} axfn;
+};
 
 // Controls that can be a button
 enum {
@@ -102,7 +102,7 @@
   BUTTON_VIEWPORT,
   BUTTON_VIEWSTARBOARD,
   BUTTON_end
-} butfn;
+};
 
 // Stick constants
 #define MAX_STICKS 4
