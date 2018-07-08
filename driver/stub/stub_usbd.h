#pragma once

#include "stub_dev.h"

#include "usb_cspkt.h"

BOOLEAN get_usb_status(usbip_stub_dev_t *devstub, USHORT op, USHORT idx, PVOID buff, PUCHAR plen);
BOOLEAN get_usb_device_desc(usbip_stub_dev_t *devstub, PUSB_DEVICE_DESCRIPTOR pdesc);
BOOLEAN get_usb_desc(usbip_stub_dev_t *devstub, UCHAR descType, UCHAR idx, USHORT idLang, PVOID buff, ULONG *pbufflen);

BOOLEAN select_usb_conf(usbip_stub_dev_t *devstub, USHORT idx);
BOOLEAN select_usb_intf(usbip_stub_dev_t *devstub, devconf_t *devconf, UCHAR intf_num, USHORT alt_setting);

BOOLEAN reset_pipe(usbip_stub_dev_t *devstub, USBD_PIPE_HANDLE hPipe);

BOOLEAN submit_class_vendor_req(usbip_stub_dev_t *devstub, BOOLEAN is_in, USHORT cmd,
	UCHAR rv, UCHAR request, USHORT value, USHORT index, PVOID data, ULONG len);

NTSTATUS
submit_bulk_intr_transfer(usbip_stub_dev_t *devstub, USBD_PIPE_HANDLE hPipe, unsigned long seqnum, PVOID data, USHORT *pdatalen, BOOLEAN is_in);

BOOLEAN
submit_control_transfer(usbip_stub_dev_t *devstub, usb_cspkt_t *csp, PVOID data, PULONG pdata_len);