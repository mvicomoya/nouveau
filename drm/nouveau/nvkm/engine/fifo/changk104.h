/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __GK104_FIFO_CHAN_H__
#define __GK104_FIFO_CHAN_H__
#define gk104_fifo_chan(p) container_of((p), struct gk104_fifo_chan, base)
#include "chan.h"
#include "gk104.h"

struct gk104_fifo_chan {
	struct nvkm_fifo_chan base;
	struct gk104_fifo *fifo;
	int runl;

	struct list_head head;
	bool killed;

	struct {
		struct nvkm_gpuobj *inst;
		struct nvkm_vma *vma;
	} engn[NVKM_SUBDEV_NR];
};

int gk104_fifo_gpfifo_new(struct gk104_fifo *, const struct nvkm_oclass *,
			  void *data, u32 size, struct nvkm_object **);
#endif
