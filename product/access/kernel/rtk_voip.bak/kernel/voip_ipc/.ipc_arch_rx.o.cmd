cmd_rtk_voip/voip_ipc/ipc_arch_rx.o := rsdk-linux-gcc -Wp,-MD,rtk_voip/voip_ipc/.ipc_arch_rx.o.d  -nostdinc -isystem /home/shipeng/EPN104N/trunk/toolchains/rsdk-1.5.6-5281-EB-2.6.30-0.9.30.3-110915/bin/../lib/gcc/mips-linux/4.4.6/include -Iinclude  -I/home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include -include include/linux/autoconf.h -Iinclude/soc -D__KERNEL__ -D"VMLINUX_LOAD_ADDRESS=0x80041000" -D"LOADADDR=0x80041000" -D"DATAOFFSET=0" -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -fno-delete-null-pointer-checks -D__LUNA_KERNEL__ -Os -fno-inline -ffunction-sections -mno-check-zero-division -mabi=32 -G 0 -mno-abicalls -fno-pic -pipe -msoft-float -ffreestanding -EB -UMIPSEB -U_MIPSEB -U__MIPSEB -U__MIPSEB__ -UMIPSEL -U_MIPSEL -U__MIPSEL -U__MIPSEL__ -DMIPSEB -D_MIPSEB -D__MIPSEB -D__MIPSEB__ -Iinclude/asm-rlx -Iarch/rlx/bsp_rtl8686/ -I/home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/mach-generic -Wframe-larger-than=1024 -fno-stack-protector -fomit-frame-pointer -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-dwarf2-cfi-asm -Irtk_voip/include -Irtk_voip/voip_dsp/include -Irtk_voip/voip_dsp/dsp_r1/include -Irtk_voip/voip_manager -Irtk_voip/voip_drivers/ -DMODULE_NAME=\"IPC\"   -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(ipc_arch_rx)"  -D"KBUILD_MODNAME=KBUILD_STR(ipc_arch_rx)"  -c -o rtk_voip/voip_ipc/ipc_arch_rx.o rtk_voip/voip_ipc/ipc_arch_rx.c

deps_rtk_voip/voip_ipc/ipc_arch_rx.o := \
  rtk_voip/voip_ipc/ipc_arch_rx.c \
    $(wildcard include/config/rtk/voip/ipc/arch/is/host.h) \
    $(wildcard include/config/rtk/voip/ipc/arch/is/dsp.h) \
    $(wildcard include/config/rtk/voip/dsp/device/nr.h) \
    $(wildcard include/config/rtk/voip/ipc/arch/issue/trivial/ack.h) \
    $(wildcard include/config/rtk/voip/ethernet/dsp/is/dsp.h) \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbd.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  include/linux/stddef.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/posix_types.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/sgidefs.h \
  /home/shipeng/EPN104N/trunk/toolchains/rsdk-1.5.6-5281-EB-2.6.30-0.9.30.3-110915/bin/../lib/gcc/mips-linux/4.4.6/include/stdarg.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/string.h \
    $(wildcard include/config/cpu/rlx4181.h) \
    $(wildcard include/config/cpu/rlx5181.h) \
  rtk_voip/include/rtk_voip.h \
    $(wildcard include/config/rtk/voip.h) \
    $(wildcard include/config/rtk/voip/drivers/pcm865xc.h) \
    $(wildcard include/config/rtk/voip/drivers/pcm8972b/family.h) \
    $(wildcard include/config/rtk/voip/drivers/pcm89xxc.h) \
    $(wildcard include/config/rtk/voip/drivers/pcm8672.h) \
    $(wildcard include/config/rtk/voip/drivers/pcm8676.h) \
    $(wildcard include/config/rtk/voip/platform/8686.h) \
    $(wildcard include/config/rtk/voip/drivers/pcm89xxd.h) \
    $(wildcard include/config/audiocodes/voip.h) \
    $(wildcard include/config/rtk/voip/drivers/ip/phone.h) \
    $(wildcard include/config/rtk/voip/wideband/support.h) \
    $(wildcard include/config/rtk/voip/g7231.h) \
    $(wildcard include/config/rtk/voip/g729ab.h) \
    $(wildcard include/config/rtk/voip/slic/si32176/nr.h) \
    $(wildcard include/config/rtk/voip/slic/si32176/cs/nr.h) \
    $(wildcard include/config/rtk/voip/slic/si32178/nr.h) \
    $(wildcard include/config/rtk/voip/slic/si32176/si32178/nr.h) \
    $(wildcard include/config/rtk/voip/slic/si3226/nr.h) \
    $(wildcard include/config/rtk/voip/slic/si3226x/nr.h) \
    $(wildcard include/config/rtk/voip/drivers/slic/le88221/nr.h) \
    $(wildcard include/config/rtk/voip/drivers/slic/le88111/nr.h) \
    $(wildcard include/config/rtk/voip/drivers/slic/le89116/nr.h) \
    $(wildcard include/config/rtk/voip/drivers/slic/le89316/nr.h) \
    $(wildcard include/config/rtk/voip/dect/dspg/hs/nr.h) \
    $(wildcard include/config/rtk/voip/dect/sitel/hs/nr.h) \
    $(wildcard include/config/rtk/voip/ip/phone/ch/nr.h) \
    $(wildcard include/config/rtk/voip/slic/ch/nr/per/dsp.h) \
    $(wildcard include/config/rtk/voip/daa/ch/nr/per/dsp.h) \
    $(wildcard include/config/rtk/voip/drivers/mirror/slic/nr.h) \
    $(wildcard include/config/rtk/voip/drivers/mirror/daa/nr.h) \
    $(wildcard include/config/rtk/voip/drivers/daa/support.h) \
    $(wildcard include/config/rtk/voip/drivers/virtual/daa.h) \
    $(wildcard include/config/rtk/voip/drivers/virtual/daa/2/relay/support.h) \
    $(wildcard include/config/rtk/voip/con/ch/num.h) \
    $(wildcard include/config/rtk/voip/bus/pcm/ch/num.h) \
    $(wildcard include/config/rtk/voip/bus/iis/ch/num.h) \
    $(wildcard include/config/rtk/voip/drivers/8186v/router.h) \
    $(wildcard include/config/rtk/voip/wan/vlan.h) \
    $(wildcard include/config/rtk/voip/clone/mac.h) \
    $(wildcard include/config/rtk/voip/drivers/pcm8186.h) \
    $(wildcard include/config/rtk/voip/gpio/8962.h) \
    $(wildcard include/config/rtk/voip/drivers/pcm8671.h) \
    $(wildcard include/config/rtk/voip/gpio/8972b.h) \
    $(wildcard include/config/rtk/voip/gpio/8954c/v100.h) \
    $(wildcard include/config/rtk/voip/gpio/8954c/v200.h) \
    $(wildcard include/config/rtk/voip/slic/num/8.h) \
    $(wildcard include/config/rtk/voip/daa/num/8.h) \
    $(wildcard include/config/rtk/voip/led.h) \
    $(wildcard include/config/rtk/voip/drivers/fxo.h) \
    $(wildcard include/config/default/new/ec128.h) \
    $(wildcard include/config/rtk/voip/t38.h) \
    $(wildcard include/config/rtk/voip/ip/phone.h) \
    $(wildcard include/config/cwmp/tr069.h) \
    $(wildcard include/config/rtk/voip/rtp/redundant.h) \
    $(wildcard include/config/rtk/voip/g7111.h) \
    $(wildcard include/config/rtk/voip/drivers/si3050.h) \
  include/linux/config.h \
    $(wildcard include/config/h.h) \
  include/linux/version.h \
  rtk_voip/include/voip_debug.h \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/panic/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  include/linux/linkage.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/linkage.h \
  include/linux/bitops.h \
    $(wildcard include/config/generic/find/first/bit.h) \
    $(wildcard include/config/generic/find/last/bit.h) \
    $(wildcard include/config/generic/find/next/bit.h) \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/bitops.h \
    $(wildcard include/config/cpu/has/llsc.h) \
    $(wildcard include/config/cpu/has/radiax.h) \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
    $(wildcard include/config/rtl/819x.h) \
  include/linux/typecheck.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/irqflags.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/hazards.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/cpu-features.h \
    $(wildcard include/config/cpu/has/ejtag.h) \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/cpu.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/cpu-info.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/cache.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/mach-generic/kmalloc.h \
    $(wildcard include/config/dma/coherent.h) \
  arch/rlx/bsp_rtl8686/bspcpu.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/barrier.h \
    $(wildcard include/config/cpu/has/sync.h) \
    $(wildcard include/config/cpu/has/wb.h) \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/break.h \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
    $(wildcard include/config/debug/bugverbose.h) \
    $(wildcard include/config/smp.h) \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/byteorder.h \
    $(wildcard include/config/cpu/big/endian.h) \
  include/linux/byteorder/big_endian.h \
  include/linux/swab.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/swab.h \
  include/linux/byteorder/generic.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/ffz.h \
  include/asm-generic/bitops/find.h \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/ext2-non-atomic.h \
  include/asm-generic/bitops/le.h \
  include/asm-generic/bitops/ext2-atomic.h \
  include/asm-generic/bitops/minix.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/ratelimit.h \
  include/linux/param.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/param.h \
    $(wildcard include/config/hz.h) \
  include/linux/dynamic_debug.h \
  rtk_voip/include/voip_timer.h \
  rtk_voip/include/voip_types.h \
    $(wildcard include/config/rtl865xb.h) \
  rtk_voip/include/voip_init.h \
    $(wildcard include/config/defaults/kernel/2/6.h) \
  include/linux/init.h \
    $(wildcard include/config/rtl8672.h) \
    $(wildcard include/config/rtl8681/ptm.h) \
    $(wildcard include/config/ethwan.h) \
    $(wildcard include/config/usb.h) \
    $(wildcard include/config/usb/rtl8187su/softap.h) \
    $(wildcard include/config/usb/rtl8192su/softap.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  include/linux/section-names.h \
  include/linux/stringify.h \
  rtk_voip/include/voip_ipc.h \
    $(wildcard include/config/rtk/voip/ipc/arch.h) \
  rtk_voip/include/voip_types.h \
  rtk_voip/include/voip_limit.h \
  rtk_voip/include/voip_dev.h \
  include/linux/fs.h \
    $(wildcard include/config/dnotify.h) \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/inotify.h) \
    $(wildcard include/config/security.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/debug/writecount.h) \
    $(wildcard include/config/pppoe/proxy.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/fs/xip.h) \
    $(wildcard include/config/migration.h) \
  include/linux/limits.h \
  include/linux/ioctl.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/ioctl.h \
  include/asm-generic/ioctl.h \
  include/linux/wait.h \
    $(wildcard include/config/lockdep.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/poison.h \
  include/linux/prefetch.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/processor.h \
    $(wildcard include/config/cpu/has/sleep.h) \
  include/linux/cpumask.h \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/linux/bitmap.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/cachectl.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/rlxregs.h \
    $(wildcard include/config/cpu/rlx5281.h) \
    $(wildcard include/config/cpu/rlx4281.h) \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/system.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/addrspace.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/mach-generic/spaces.h \
    $(wildcard include/config/32bit.h) \
    $(wildcard include/config/dma/noncoherent.h) \
  include/linux/const.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/cmpxchg.h \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/thread_info.h \
    $(wildcard include/config/kernel/stack/size/order.h) \
    $(wildcard include/config/debug/stack/usage.h) \
  include/linux/bottom_half.h \
  include/linux/spinlock_types.h \
  include/linux/spinlock_types_up.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/generic/hardirqs.h) \
  include/linux/spinlock_up.h \
  include/linux/spinlock_api_up.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/atomic.h \
  include/asm-generic/atomic-long.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/current.h \
  include/linux/kdev_t.h \
  include/linux/dcache.h \
  include/linux/rculist.h \
  include/linux/rcupdate.h \
    $(wildcard include/config/classic/rcu.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/preempt/rcu.h) \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  include/linux/seqlock.h \
  include/linux/completion.h \
  include/linux/rcuclassic.h \
    $(wildcard include/config/rcu/cpu/stall/detector.h) \
  include/linux/path.h \
  include/linux/stat.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/stat.h \
  include/linux/time.h \
  include/linux/math64.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/div64.h \
  include/asm-generic/div64.h \
  include/linux/kobject.h \
  include/linux/sysfs.h \
  include/linux/errno.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/errno.h \
  include/asm-generic/errno-base.h \
  include/linux/kref.h \
  include/linux/radix-tree.h \
  include/linux/prio_tree.h \
  include/linux/pid.h \
  include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
  include/linux/capability.h \
    $(wildcard include/config/security/file/capabilities.h) \
  include/linux/semaphore.h \
  include/linux/fiemap.h \
  include/linux/quota.h \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  include/linux/rwsem-spinlock.h \
  include/linux/dqblk_xfs.h \
  include/linux/dqblk_v1.h \
  include/linux/dqblk_v2.h \
  include/linux/dqblk_qtree.h \
  include/linux/nfs_fs_i.h \
  include/linux/nfs.h \
  include/linux/sunrpc/msg_prot.h \
  include/linux/fcntl.h \
  /home/shipeng/EPN104N/trunk/product/access/kernel/linux-2.6.x/arch/rlx/include/asm/fcntl.h \
  include/asm-generic/fcntl.h \
  include/linux/err.h \
  rtk_voip/include/voip_timer.h \
  rtk_voip/voip_ipc/../voip_manager/voip_mgr_netfilter.h \
  rtk_voip/voip_ipc/../voip_manager/../include/voip_types.h \
  rtk_voip/voip_ipc/../voip_manager/../include/voip_params.h \
  rtk_voip/voip_ipc/../voip_manager/../include/rtk_voip.h \
  rtk_voip/voip_ipc/../voip_manager/../include/voip_control.h \
    $(wildcard include/config/rtk/voip/srtp.h) \
  rtk_voip/voip_ipc/../voip_manager/../include/voip_params.h \
  rtk_voip/voip_ipc/../voip_manager/../include/rtk_voip.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/Rtp.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/rtpTypes.h \
    $(wildcard include/config/rtk/voip/rtcp/xr.h) \
  rtk_voip/include/voip_params.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/NtpTime.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/rtpTypesXR.h \
  rtk_voip/voip_dsp/include/codec_descriptor.h \
    $(wildcard include/config/rtk/voip/g722.h) \
    $(wildcard include/config/rtk/voip/g726.h) \
    $(wildcard include/config/rtk/voip/gsmfr.h) \
    $(wildcard include/config/rtk/voip/ilbc.h) \
    $(wildcard include/config/rtk/voip/amr/nb.h) \
    $(wildcard include/config/rtk/voip/speex/nb.h) \
    $(wildcard include/config/rtk/voip/pcm/linear/8k.h) \
    $(wildcard include/config/rtk/voip/pcm/linear/16k.h) \
    $(wildcard include/config/rtk/voip/silence.h) \
  rtk_voip/voip_dsp/include/../dsp_r1/include/dspcodec.h \
    $(wildcard include/config/done.h) \
  rtk_voip/voip_dsp/include/../dsp_r1/include/typedef.h \
  rtk_voip/include/codec_def.h \
  rtk_voip/include/rtk_voip.h \
  rtk_voip/voip_dsp/include/dsp_rtp_def.h \
  rtk_voip/voip_dsp/include/dsp_main.h \
  rtk_voip/voip_dsp/include/../rtp/RtpPacket.h \
  rtk_voip/voip_dsp/include/../rtp/rtpTypes.h \
  rtk_voip/voip_dsp/include/assert.h \
  rtk_voip/voip_dsp/include/../rtp/RtcpPacket.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/RtpPacket.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/RtpTransmitter.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/RtpReceiver.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/RtcpReceiver.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/RtcpPacket.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/rtpterm.h \
  rtk_voip/include/voip_control.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/rtp_main.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/Rtcp.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/rtp/RtcpTransmitter.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/dsp_r0/dspcodec_0.h \
  rtk_voip/voip_dsp/dsp_r1/include/dspcodec.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_dsp/dsp_r1/include/dspcodec.h \
  rtk_voip/voip_ipc/../voip_manager/../voip_drivers/snd_mux_slic.h \
  rtk_voip/voip_ipc/../voip_manager/voip_resource_check.h \
    $(wildcard include/config/rtk/voip/daa/num/1.h) \
    $(wildcard include/config/rtk/voip/daa/num/2.h) \
    $(wildcard include/config/rtk/voip/daa/num/3.h) \
    $(wildcard include/config/rtk/voip/daa/num/4.h) \
    $(wildcard include/config/rtk/voip/drivers/pcm8651.h) \
    $(wildcard include/config/rtk/voip/gpio/8651c.h) \
    $(wildcard include/config/rtk/voip/gpio/ipp/8952/v00.h) \
  rtk_voip/voip_drivers/con_mux.h \
  rtk_voip/voip_drivers/con_register.h \
  rtk_voip/voip_drivers/con_define.h \
  rtk_voip/voip_ipc/../voip_manager/voip_mgr_events.h \
  rtk_voip/voip_ipc/ipc_internal.h \
  rtk_voip/voip_ipc/ipc_arch_tx.h \
  rtk_voip/voip_manager/voip_mgr_define.h \
  rtk_voip/voip_ipc/ipc_arch_rx.h \

rtk_voip/voip_ipc/ipc_arch_rx.o: $(deps_rtk_voip/voip_ipc/ipc_arch_rx.o)

$(deps_rtk_voip/voip_ipc/ipc_arch_rx.o):
