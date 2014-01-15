#ifndef _NFS_FS_I
#define _NFS_FS_I

struct nlm_lockowner;

/*
 * NFS lock info
 */
struct nfs_lock_info {
	u32		state;
	struct nlm_lockowner *owner;
#ifdef __KERNEL__
	struct list_head list;
#endif
};

struct nfs4_lock_state;
struct nfs4_lock_info {
	struct nfs4_lock_state *owner;
};

#endif
