/*
 * Platform data for the chipidea USB dual role controller
 */

#ifndef __LINUX_USB_CHIPIDEA_H
#define __LINUX_USB_CHIPIDEA_H

#include <linux/usb/otg.h>

struct ci_hdrc;
struct ci_hdrc_platform_data {
	const char	*name;
	/* offset of the capability registers */
	uintptr_t	 capoffset;
	unsigned	 power_budget;
	struct usb_phy	*phy;
	enum usb_phy_interface phy_mode;
	unsigned long	 flags;
#define CI_HDRC_REGS_SHARED		BIT(0)
#define CI_HDRC_REQUIRE_TRANSCEIVER	BIT(1)
#define CI_HDRC_SUPPORTS_RUNTIME_PM	BIT(2)
#define CI_HDRC_DISABLE_STREAMING	BIT(3)
	/*
	 * Only set it when DCCPARAMS.DC==1 and DCCPARAMS.HC==1,
	 * but otg is not supported (no register otgsc).
	 */
#define CI_HDRC_DUAL_ROLE_NOT_OTG	BIT(4)
#define CI_HDRC_IMX28_WRITE_FIX		BIT(5)
#define CI_HDRC_IMX_EHCI_QUIRK		BIT(6)
	enum usb_dr_mode	dr_mode;
#define CI_HDRC_CONTROLLER_RESET_EVENT		0
#define CI_HDRC_CONTROLLER_STOPPED_EVENT	1
#define CI_HDRC_CONTROLLER_CHARGER_EVENT	2
#define CI_HDRC_CONTROLLER_CHARGER_POST_EVENT	3
	int	(*notify_event) (struct ci_hdrc *ci, unsigned event);
#define CI_HDRC_NOTIFY_RET_DEFER_EVENT		1
	struct regulator	*reg_vbus;
};

/* Default offset of capability registers */
#define DEF_CAPOFFSET		0x100

/* Add ci hdrc device */
struct platform_device *ci_hdrc_add_device(struct device *dev,
			struct resource *res, int nres,
			struct ci_hdrc_platform_data *platdata);
/* Remove ci hdrc device */
void ci_hdrc_remove_device(struct platform_device *pdev);

#endif
