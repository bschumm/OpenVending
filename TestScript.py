import serial
import pprint

ser = serial.Serial(1)
print ser.name
while 1==1:

    status = "31".decode("hex");
    credit = "32".decode("hex");
    vend = "33".decode("hex");
    audit = "34".decode("hex");
    send_audit_address = "35".decode("hex");
    send_audit_data = "36".decode("hex");
    identify = "37".decode("hex");
    accept_data = "38".decode("hex");
    data_sync = "39".decode("hex");
    nack = "3F".decode("hex");
 
    x = ser.read()

    if x == status:
        ser.write(bytearray([0x00]))
        print 'Status | Answer OK - 0x00'
    elif x == credit:
        ser.write(bytearray([0x64]))
        print 'Credit | Answer 50 - 0x64'
    elif x == vend:
        ser.write(bytearray([0x80]))
        print 'Vend | Answer Failed - 0x80'
    elif x == audit:
        ser.write(bytearray([0x32]))
        print 'Audit | Answer - 0x00'
    elif x == send_audit_address:
        ser.write(bytearray([0x07]))
        print 'Audit Address| Total Money - 0x07'
    elif x == send_audit_data:
        ser.write(bytearray([0x07]))
        print 'Audit Data | Total Money - 0x07'    
    elif x == accept_data:
        ser.write(bytearray([0x00]))
        print 'ACCEPT DATA | Answer 0x00'
    elif x == nack:
        print 'Fehler'
    elif x == data_sync:
        ser.write(bytearray([0x00]))
        print 'DATA SYNC | Answer 0x00'
    else:
        print 'Unknown Command'
        print x
