#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netdevice.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#include <linux/skbuff.h>


static int skb_test(void)
{
	struct sk_buff *skb;
	struct iphdr *iph;
	struct udphdr *udph;
	struct tcphdr *tcph;
	int ret = 0;

//	while (ret != 100) {

	netif_receive_skb(skb);

		iph = ip_hdr(skb);
		if (iph->protocol == IPPROTO_UDP) {
			udph = udp_hdr(skb);
			printk("dest UDP %i\n", ntohs(udph->dest));
		}
		else if (iph->protocol == IPPROTO_TCP) {
			tcph = tcp_hdr(skb);
			printk("dest TCP %i\n", ntohs(tcph->dest));

		}

		ret++;
	//}*/
}

static int __init LKM_init(void)
{

	skb_test();
	return 0;
}

static void __exit LKM_exit(void)
{
}

module_init(LKM_init);
module_exit(LKM_exit);
MODULE_LICENSE("GPL");
