//
//  ORSSerialPortDemoController.h
//  ORSSerialPortDemo
//
//  Created by Andrew R. Madsen on 6/27/12.
//	Copyright (c) 2012-2014 Andrew R. Madsen (andrew@openreelsoftware.com)
//	
//	Permission is hereby granted, free of charge, to any person obtaining a
//	copy of this software and associated documentation files (the
//	"Software"), to deal in the Software without restriction, including
//	without limitation the rights to use, copy, modify, merge, publish,
//	distribute, sublicense, and/or sell copies of the Software, and to
//	permit persons to whom the Software is furnished to do so, subject to
//	the following conditions:
//	
//	The above copyright notice and this permission notice shall be included
//	in all copies or substantial portions of the Software.
//	
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//	OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//	IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
//	CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
//	TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//	SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import <Cocoa/Cocoa.h>
#import "ORSSerialPort.h"
#import <Foundation/Foundation.h>

@class ORSSerialPortManager;

#if (MAC_OS_X_VERSION_MAX_ALLOWED <= MAC_OS_X_VERSION_10_7)
@protocol NSUserNotificationCenterDelegate <NSObject>
@end
#endif

static id monitorLeftMouseDown;
static id monitorRightMouseDown;
static id monitorKeyDown;
static id monitorMouseMoved;
bool wasCapsLockDown;
id capsLockEventMonitor;
id mouseMovementEventMonitor;

@interface ORSSerialPortDemoController : NSObject <ORSSerialPortDelegate, NSUserNotificationCenterDelegate>



@property (readwrite) BOOL loggingEnabled;

- (IBAction)stopButtonPressed:(id)sender;
- (IBAction)startButtonPressed:(id)sender;
- (IBAction)clearButtonPressed:(id)sender;

- (void)logMessageToLogView:(NSString*)message;

- (BOOL)validateToolbarItem:(NSToolbarItem *)theItem;



-(void)beginEventMonitoring;
-(void)endEventMonitoring;

-(void)simulateMouseEvent:(CGEventType)eventType;




- (IBAction)send:(id)sender;
- (IBAction)openOrClosePort:(id)sender;

@property (unsafe_unretained) IBOutlet NSTextField *sendTextField;
@property (unsafe_unretained) IBOutlet NSTextView *receivedDataTextView;
@property (unsafe_unretained) IBOutlet NSButton *openCloseButton;

@property (nonatomic, strong) ORSSerialPortManager *serialPortManager;
@property (nonatomic, strong) ORSSerialPort *serialPort;
@property (nonatomic, strong) NSArray *availableBaudRates;

@end