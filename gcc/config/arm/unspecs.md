;; Unspec defintions.
;; Copyright (C) 2012-2020 Free Software Foundation, Inc.
;; Contributed by ARM Ltd.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify it
;; under the terms of the GNU General Public License as published
;; by the Free Software Foundation; either version 3, or (at your
;; option) any later version.

;; GCC is distributed in the hope that it will be useful, but WITHOUT
;; ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
;; or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
;; License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

;; UNSPEC Usage:
;; Note: sin and cos are no-longer used.
;; Unspec enumerators for Neon are defined in neon.md.
;; Unspec enumerators for iwmmxt2 are defined in iwmmxt2.md

(define_c_enum "unspec" [
  UNSPEC_PUSH_MULT      ; `push multiple' operation:
                        ;   operand 0 is the first register,
                        ;   subsequent registers are in parallel (use ...)
                        ;   expressions.
  UNSPEC_PIC_SYM        ; A symbol that has been treated properly for pic
                        ; usage, that is, we will add the pic_register
                        ; value to it before trying to dereference it.
  UNSPEC_PIC_BASE       ; Add PC and all but the last operand together,
                        ; The last operand is the number of a PIC_LABEL
                        ; that points at the containing instruction.
  UNSPEC_PRLG_STK       ; A special barrier that prevents frame accesses
                        ; being scheduled before the stack adjustment insn.
  UNSPEC_REGISTER_USE   ; As USE insns are not meaningful after reload,
                        ; this unspec is used to prevent the deletion of
                        ; instructions setting registers for EH handling
                        ; and stack frame generation.  Operand 0 is the
                        ; register to "use".
  UNSPEC_CHECK_ARCH     ; Set CCs to indicate 26-bit or 32-bit mode.
  UNSPEC_WSHUFH         ; Used by the intrinsic form of the iWMMXt WSHUFH instruction.
  UNSPEC_WACC           ; Used by the intrinsic form of the iWMMXt WACC instruction.
  UNSPEC_TMOVMSK        ; Used by the intrinsic form of the iWMMXt TMOVMSK instruction.
  UNSPEC_WSAD           ; Used by the intrinsic form of the iWMMXt WSAD instruction.
  UNSPEC_WSADZ          ; Used by the intrinsic form of the iWMMXt WSADZ instruction.
  UNSPEC_WMACS          ; Used by the intrinsic form of the iWMMXt WMACS instruction.
  UNSPEC_WMACU          ; Used by the intrinsic form of the iWMMXt WMACU instruction.
  UNSPEC_WMACSZ         ; Used by the intrinsic form of the iWMMXt WMACSZ instruction.
  UNSPEC_WMACUZ         ; Used by the intrinsic form of the iWMMXt WMACUZ instruction.
  UNSPEC_CLRDI          ; Used by the intrinsic form of the iWMMXt CLRDI instruction.
  UNSPEC_WALIGNI        ; Used by the intrinsic form of the iWMMXt WALIGN instruction.
  UNSPEC_TLS            ; A symbol that has been treated properly for TLS usage.
  UNSPEC_PIC_LABEL      ; A label used for PIC access that does not appear in the
                        ; instruction stream.
  UNSPEC_PIC_OFFSET     ; A symbolic 12-bit OFFSET that has been treated
                        ; correctly for PIC usage.
  UNSPEC_GOTSYM_OFF     ; The offset of the start of the GOT from a
                        ; a given symbolic address.
  UNSPEC_THUMB1_CASESI  ; A Thumb1 compressed dispatch-table call.
  UNSPEC_RBIT           ; rbit operation.
  UNSPEC_SYMBOL_OFFSET  ; The offset of the start of the symbol from
                        ; another symbolic address.
  UNSPEC_MEMORY_BARRIER ; Represent a memory barrier.
  UNSPEC_UNALIGNED_LOAD	; Used to represent ldr/ldrh instructions that access
			; unaligned locations, on architectures which support
			; that.
  UNSPEC_UNALIGNED_STORE ; Same for str/strh.
  UNSPEC_PIC_UNIFIED    ; Create a common pic addressing form.
  UNSPEC_Q_SET          ; Represent setting the Q bit.
  UNSPEC_GE_SET         ; Represent setting the GE bits.
  UNSPEC_APSR_READ      ; Represent reading the APSR.

  UNSPEC_LL		; Represent an unpaired load-register-exclusive.
  UNSPEC_VRINTZ         ; Represent a float to integral float rounding
                        ; towards zero.
  UNSPEC_VRINTP         ; Represent a float to integral float rounding
                        ; towards +Inf.
  UNSPEC_VRINTM         ; Represent a float to integral float rounding
                        ; towards -Inf.
  UNSPEC_VRINTR         ; Represent a float to integral float rounding
                        ; FPSCR rounding mode.
  UNSPEC_VRINTX         ; Represent a float to integral float rounding
                        ; FPSCR rounding mode and signal inexactness.
  UNSPEC_VRINTA         ; Represent a float to integral float rounding
                        ; towards nearest, ties away from zero.
  UNSPEC_PROBE_STACK    ; Probe stack memory reference
  UNSPEC_NONSECURE_MEM	; Represent non-secure memory in ARMv8-M with
			; security extension
  UNSPEC_SP_SET		; Represent the setting of stack protector's canary
  UNSPEC_SP_TEST	; Represent the testing of stack protector's canary
			; against the guard.
  UNSPEC_PIC_RESTORE	; Use to restore fdpic register

  UNSPEC_SXTAB16	; Represent the SXTAB16 operation.
  UNSPEC_UXTAB16	; Represent the UXTAB16 operation.
  UNSPEC_SXTB16		; Represent the SXTB16 operation.
  UNSPEC_UXTB16		; Represent the UXTB16 operation.
  UNSPEC_QADD8		; Represent the QADD8 operation.
  UNSPEC_QSUB8		; Represent the QSUB8 operation.
  UNSPEC_SHADD8		; Represent the SHADD8 operation.
  UNSPEC_SHSUB8		; Represent the SHSUB8 operation.
  UNSPEC_UHADD8		; Represent the UHADD8 operation.
  UNSPEC_UHSUB8		; Represent the UHSUB8 operation.
  UNSPEC_UQADD8		; Represent the UQADD8 operation.
  UNSPEC_UQSUB8		; Represent the UQSUB8 operation.
  UNSPEC_QADD16		; Represent the QADD16 operation.
  UNSPEC_QASX		; Represent the QASX operation.
  UNSPEC_QSAX		; Represent the QSAX operation.
  UNSPEC_QSUB16		; Represent the QSUB16 operation.
  UNSPEC_SHADD16	; Represent the SHADD16 operation.
  UNSPEC_SHASX		; Represent the SHASX operation.
  UNSPEC_SHSAX		; Represent the SSAX operation.
  UNSPEC_SHSUB16	; Represent the SHSUB16 operation.
  UNSPEC_UHADD16	; Represent the UHADD16 operation.
  UNSPEC_UHASX		; Represent the UHASX operation.
  UNSPEC_UHSAX		; Represent the USAX operation.
  UNSPEC_UHSUB16	; Represent the UHSUB16 operation.
  UNSPEC_UQADD16	; Represent the UQADD16 operation.
  UNSPEC_UQASX		; Represent the UQASX operation.
  UNSPEC_UQSAX		; Represent the UQSAX operation.
  UNSPEC_UQSUB16	; Represent the UQSUB16 operation.
  UNSPEC_SMUSD		; Represent the SMUSD operation.
  UNSPEC_SMUSDX		; Represent the SMUSDX operation.
  UNSPEC_USAD8		; Represent the USAD8 operation.
  UNSPEC_USADA8		; Represent the USADA8 operation.
  UNSPEC_SMLALD		; Represent the SMLALD operation.
  UNSPEC_SMLALDX	; Represent the SMLALDX operation.
  UNSPEC_SMLSLD		; Represent the SMLSLD operation.
  UNSPEC_SMLSLDX	; Represent the SMLSLDX operation.
  UNSPEC_SMLAWB		; Represent the SMLAWB operation.
  UNSPEC_SMLAWT		; Represent the SMLAWT operation.
  UNSPEC_SEL		; Represent the SEL operation.
  UNSPEC_SADD8		; Represent the SADD8 operation.
  UNSPEC_SSUB8		; Represent the SSUB8 operation.
  UNSPEC_UADD8		; Represent the UADD8 operation.
  UNSPEC_USUB8		; Represent the USUB8 operation.
  UNSPEC_SADD16		; Represent the SADD16 operation.
  UNSPEC_SASX		; Represent the SASX operation.
  UNSPEC_SSAX		; Represent the SSAX operation.
  UNSPEC_SSUB16		; Represent the SSUB16 operation.
  UNSPEC_UADD16		; Represent the UADD16 operation.
  UNSPEC_UASX		; Represent the UASX operation.
  UNSPEC_USAX		; Represent the USAX operation.
  UNSPEC_USUB16		; Represent the USUB16 operation.
  UNSPEC_SMLAD		; Represent the SMLAD operation.
  UNSPEC_SMLADX		; Represent the SMLADX operation.
  UNSPEC_SMLSD		; Represent the SMLSD operation.
  UNSPEC_SMLSDX		; Represent the SMLSDX operation.
  UNSPEC_SMUAD		; Represent the SMUAD operation.
  UNSPEC_SMUADX		; Represent the SMUADX operation.
  UNSPEC_SSAT16		; Represent the SSAT16 operation.
  UNSPEC_USAT16		; Represent the USAT16 operation.
])


(define_c_enum "unspec" [
  UNSPEC_WADDC		; Used by the intrinsic form of the iWMMXt WADDC instruction.
  UNSPEC_WABS		; Used by the intrinsic form of the iWMMXt WABS instruction.
  UNSPEC_WQMULWMR	; Used by the intrinsic form of the iWMMXt WQMULWMR instruction.
  UNSPEC_WQMULMR	; Used by the intrinsic form of the iWMMXt WQMULMR instruction.
  UNSPEC_WQMULWM	; Used by the intrinsic form of the iWMMXt WQMULWM instruction.
  UNSPEC_WQMULM		; Used by the intrinsic form of the iWMMXt WQMULM instruction.
  UNSPEC_WQMIAxyn	; Used by the intrinsic form of the iWMMXt WMIAxyn instruction.
  UNSPEC_WQMIAxy	; Used by the intrinsic form of the iWMMXt WMIAxy instruction.
  UNSPEC_TANDC		; Used by the intrinsic form of the iWMMXt TANDC instruction.
  UNSPEC_TORC		; Used by the intrinsic form of the iWMMXt TORC instruction.
  UNSPEC_TORVSC		; Used by the intrinsic form of the iWMMXt TORVSC instruction.
  UNSPEC_TEXTRC		; Used by the intrinsic form of the iWMMXt TEXTRC instruction.
  UNSPEC_GET_FPSCR_NZCVQC	; Represent fetch of FPSCR_nzcvqc content.
])


;; UNSPEC_VOLATILE Usage:

(define_c_enum "unspecv" [
  VUNSPEC_BLOCKAGE      ; `blockage' insn to prevent scheduling across an
                        ;   insn in the code.
  VUNSPEC_EPILOGUE      ; `epilogue' insn, used to represent any part of the
                        ;   instruction epilogue sequence that isn't expanded
                        ;   into normal RTL.  Used for both normal and sibcall
                        ;   epilogues.
  VUNSPEC_THUMB1_INTERWORK ; `prologue_thumb1_interwork' insn, used to swap
			;   modes from arm to thumb.
  VUNSPEC_ALIGN         ; `align' insn.  Used at the head of a minipool table
                        ;   for inlined constants.
  VUNSPEC_POOL_END      ; `end-of-table'.  Used to mark the end of a minipool
                        ;   table.
  VUNSPEC_POOL_1        ; `pool-entry(1)'.  An entry in the constant pool for
                        ;   an 8-bit object.
  VUNSPEC_POOL_2        ; `pool-entry(2)'.  An entry in the constant pool for
                        ;   a 16-bit object.
  VUNSPEC_POOL_4        ; `pool-entry(4)'.  An entry in the constant pool for
                        ;   a 32-bit object.
  VUNSPEC_POOL_8        ; `pool-entry(8)'.  An entry in the constant pool for
                        ;   a 64-bit object.
  VUNSPEC_POOL_16       ; `pool-entry(16)'.  An entry in the constant pool for
                        ;   a 128-bit object.
  VUNSPEC_TMRC          ; Used by the iWMMXt TMRC instruction.
  VUNSPEC_TMCR          ; Used by the iWMMXt TMCR instruction.
  VUNSPEC_ALIGN8        ; 8-byte alignment version of VUNSPEC_ALIGN
  VUNSPEC_WCMP_EQ       ; Used by the iWMMXt WCMPEQ instructions
  VUNSPEC_WCMP_GTU      ; Used by the iWMMXt WCMPGTU instructions
  VUNSPEC_WCMP_GT       ; Used by the iwMMXT WCMPGT instructions
  VUNSPEC_EH_RETURN     ; Use to override the return address for exception
                        ; handling.
  VUNSPEC_ATOMIC_CAS	; Represent an atomic compare swap.
  VUNSPEC_ATOMIC_XCHG	; Represent an atomic exchange.
  VUNSPEC_ATOMIC_OP	; Represent an atomic operation.
  VUNSPEC_LL		; Represent a load-register-exclusive.
  VUNSPEC_LDRD_ATOMIC	; Represent an LDRD used as an atomic DImode load.
  VUNSPEC_SC		; Represent a store-register-exclusive.
  VUNSPEC_LAX		; Represent a load-register-acquire-exclusive.
  VUNSPEC_SLX		; Represent a store-register-release-exclusive.
  VUNSPEC_LDA		; Represent a store-register-acquire.
  VUNSPEC_STL		; Represent a store-register-release.
  VUNSPEC_GET_FPSCR	; Represent fetch of FPSCR content.
  VUNSPEC_SET_FPSCR	; Represent assign of FPSCR content.
  VUNSPEC_SET_FPSCR_NZCVQC	; Represent assign of FPSCR_nzcvqc content.
  VUNSPEC_PROBE_STACK_RANGE ; Represent stack range probing.
  VUNSPEC_CDP		; Represent the coprocessor cdp instruction.
  VUNSPEC_CDP2		; Represent the coprocessor cdp2 instruction.
  VUNSPEC_LDC		; Represent the coprocessor ldc instruction.
  VUNSPEC_LDC2		; Represent the coprocessor ldc2 instruction.
  VUNSPEC_LDCL		; Represent the coprocessor ldcl instruction.
  VUNSPEC_LDC2L		; Represent the coprocessor ldc2l instruction.
  VUNSPEC_STC		; Represent the coprocessor stc instruction.
  VUNSPEC_STC2		; Represent the coprocessor stc2 instruction.
  VUNSPEC_STCL		; Represent the coprocessor stcl instruction.
  VUNSPEC_STC2L		; Represent the coprocessor stc2l instruction.
  VUNSPEC_MCR		; Represent the coprocessor mcr instruction.
  VUNSPEC_MCR2		; Represent the coprocessor mcr2 instruction.
  VUNSPEC_MRC		; Represent the coprocessor mrc instruction.
  VUNSPEC_MRC2		; Represent the coprocessor mrc2 instruction.
  VUNSPEC_MCRR		; Represent the coprocessor mcrr instruction.
  VUNSPEC_MCRR2		; Represent the coprocessor mcrr2 instruction.
  VUNSPEC_MRRC		; Represent the coprocessor mrrc instruction.
  VUNSPEC_MRRC2		; Represent the coprocessor mrrc2 instruction.
  VUNSPEC_SPECULATION_BARRIER ; Represents an unconditional speculation barrier.
  VUNSPEC_APSR_WRITE     ; Represent writing the APSR.
  VUNSPEC_VSTR_VLDR	; Represent the vstr/vldr instruction.
  VUNSPEC_CLRM_APSR	; Represent the clearing of APSR with clrm instruction.
  VUNSPEC_VSCCLRM_VPR	; Represent the clearing of VPR with vscclrm
			; instruction.
  VUNSPEC_VLSTM		; Represent the lazy store multiple with vlstm
			; instruction.
  VUNSPEC_VLLDM		; Represent the lazy load multiple with vlldm
			; instruction.
])

;; Enumerators for NEON unspecs.
(define_c_enum "unspec" [
  UNSPEC_ASHIFT_SIGNED
  UNSPEC_ASHIFT_UNSIGNED
  UNSPEC_CRC32B
  UNSPEC_CRC32H
  UNSPEC_CRC32W
  UNSPEC_CRC32CB
  UNSPEC_CRC32CH
  UNSPEC_CRC32CW
  UNSPEC_AESD
  UNSPEC_AESE
  UNSPEC_AESIMC
  UNSPEC_AESMC
  UNSPEC_SHA1C
  UNSPEC_SHA1M
  UNSPEC_SHA1P
  UNSPEC_SHA1H
  UNSPEC_SHA1SU0
  UNSPEC_SHA1SU1
  UNSPEC_SHA256H
  UNSPEC_SHA256H2
  UNSPEC_SHA256SU0
  UNSPEC_SHA256SU1
  UNSPEC_VMULLP64
  UNSPEC_LOAD_COUNT
  UNSPEC_VABAL_S
  UNSPEC_VABAL_U
  UNSPEC_VABD_F
  UNSPEC_VABD_S
  UNSPEC_VABD_U
  UNSPEC_VABDL_S
  UNSPEC_VABDL_U
  UNSPEC_VADD
  UNSPEC_VADDHN
  UNSPEC_VRADDHN
  UNSPEC_VADDL_S
  UNSPEC_VADDL_U
  UNSPEC_VADDW_S
  UNSPEC_VADDW_U
  UNSPEC_VBSL
  UNSPEC_VCAGE
  UNSPEC_VCAGT
  UNSPEC_VCALE
  UNSPEC_VCALT
  UNSPEC_VCEQ
  UNSPEC_VCGE
  UNSPEC_VCGEU
  UNSPEC_VCGT
  UNSPEC_VCGTU
  UNSPEC_VCLS
  UNSPEC_VCONCAT
  UNSPEC_VCVT
  UNSPEC_VCVT_S
  UNSPEC_VCVT_U
  UNSPEC_VCVT_S_N
  UNSPEC_VCVT_U_N
  UNSPEC_VCVT_HF_S_N
  UNSPEC_VCVT_HF_U_N
  UNSPEC_VCVT_SI_S_N
  UNSPEC_VCVT_SI_U_N
  UNSPEC_VCVTH_S
  UNSPEC_VCVTH_U
  UNSPEC_VCVTA_S
  UNSPEC_VCVTA_U
  UNSPEC_VCVTM_S
  UNSPEC_VCVTM_U
  UNSPEC_VCVTN_S
  UNSPEC_VCVTN_U
  UNSPEC_VCVTP_S
  UNSPEC_VCVTP_U
  UNSPEC_VEXT
  UNSPEC_VHADD_S
  UNSPEC_VHADD_U
  UNSPEC_VRHADD_S
  UNSPEC_VRHADD_U
  UNSPEC_VHSUB_S
  UNSPEC_VHSUB_U
  UNSPEC_VLD1
  UNSPEC_VLD1_LANE
  UNSPEC_VLD2
  UNSPEC_VLD2_DUP
  UNSPEC_VLD2_LANE
  UNSPEC_VLD3
  UNSPEC_VLD3A
  UNSPEC_VLD3B
  UNSPEC_VLD3_DUP
  UNSPEC_VLD3_LANE
  UNSPEC_VLD4
  UNSPEC_VLD4A
  UNSPEC_VLD4B
  UNSPEC_VLD4_DUP
  UNSPEC_VLD4_LANE
  UNSPEC_VMAX
  UNSPEC_VMAX_U
  UNSPEC_VMAXNM
  UNSPEC_VMIN
  UNSPEC_VMIN_U
  UNSPEC_VMINNM
  UNSPEC_VMLA
  UNSPEC_VMLA_LANE
  UNSPEC_VMLAL_S
  UNSPEC_VMLAL_U
  UNSPEC_VMLAL_S_LANE
  UNSPEC_VMLAL_U_LANE
  UNSPEC_VMLS
  UNSPEC_VMLS_LANE
  UNSPEC_VMLSL_S
  UNSPEC_VMLSL_U
  UNSPEC_VMLSL_S_LANE
  UNSPEC_VMLSL_U_LANE
  UNSPEC_VMLSL_LANE
  UNSPEC_VFMA_LANE
  UNSPEC_VFMS_LANE
  UNSPEC_VMOVL_S
  UNSPEC_VMOVL_U
  UNSPEC_VMOVN
  UNSPEC_VMUL
  UNSPEC_VMULL_P
  UNSPEC_VMULL_S
  UNSPEC_VMULL_U
  UNSPEC_VMUL_LANE
  UNSPEC_VMULL_S_LANE
  UNSPEC_VMULL_U_LANE
  UNSPEC_VPADAL_S
  UNSPEC_VPADAL_U
  UNSPEC_VPADD
  UNSPEC_VPADDL_S
  UNSPEC_VPADDL_U
  UNSPEC_VPMAX
  UNSPEC_VPMAX_U
  UNSPEC_VPMIN
  UNSPEC_VPMIN_U
  UNSPEC_VPSMAX
  UNSPEC_VPSMIN
  UNSPEC_VPUMAX
  UNSPEC_VPUMIN
  UNSPEC_VQABS
  UNSPEC_VQADD_S
  UNSPEC_VQADD_U
  UNSPEC_VQDMLAL
  UNSPEC_VQDMLAL_LANE
  UNSPEC_VQDMLSL
  UNSPEC_VQDMLSL_LANE
  UNSPEC_VQDMULH
  UNSPEC_VQDMULH_LANE
  UNSPEC_VQRDMULH
  UNSPEC_VQRDMULH_LANE
  UNSPEC_VQDMULL
  UNSPEC_VQDMULL_LANE
  UNSPEC_VQMOVN_S
  UNSPEC_VQMOVN_U
  UNSPEC_VQMOVUN
  UNSPEC_VQNEG
  UNSPEC_VQSHL_S
  UNSPEC_VQSHL_U
  UNSPEC_VQRSHL_S
  UNSPEC_VQRSHL_U
  UNSPEC_VQSHL_S_N
  UNSPEC_VQSHL_U_N
  UNSPEC_VQSHLU_N
  UNSPEC_VQSHRN_S_N
  UNSPEC_VQSHRN_U_N
  UNSPEC_VQRSHRN_S_N
  UNSPEC_VQRSHRN_U_N
  UNSPEC_VQSHRUN_N
  UNSPEC_VQRSHRUN_N
  UNSPEC_VQSUB_S
  UNSPEC_VQSUB_U
  UNSPEC_VRECPE
  UNSPEC_VRECPS
  UNSPEC_VREV16
  UNSPEC_VREV32
  UNSPEC_VREV64
  UNSPEC_VRSQRTE
  UNSPEC_VRSQRTS
  UNSPEC_VSHL_S
  UNSPEC_VSHL_U
  UNSPEC_VRSHL_S
  UNSPEC_VRSHL_U
  UNSPEC_VSHLL_S_N
  UNSPEC_VSHLL_U_N
  UNSPEC_VSHL_N
  UNSPEC_VSHR_S_N
  UNSPEC_VSHR_U_N
  UNSPEC_VRSHR_S_N
  UNSPEC_VRSHR_U_N
  UNSPEC_VSHRN_N
  UNSPEC_VRSHRN_N
  UNSPEC_VSLI
  UNSPEC_VSRA_S_N
  UNSPEC_VSRA_U_N
  UNSPEC_VRSRA_S_N
  UNSPEC_VRSRA_U_N
  UNSPEC_VSRI
  UNSPEC_VST1
  UNSPEC_VST1_LANE
  UNSPEC_VST2
  UNSPEC_VST2_LANE
  UNSPEC_VST3
  UNSPEC_VST3A
  UNSPEC_VST3B
  UNSPEC_VST3_LANE
  UNSPEC_VST4
  UNSPEC_VST4A
  UNSPEC_VST4B
  UNSPEC_VST4_LANE
  UNSPEC_VSTRUCTDUMMY
  UNSPEC_VSUB
  UNSPEC_VSUBHN
  UNSPEC_VRSUBHN
  UNSPEC_VSUBL_S
  UNSPEC_VSUBL_U
  UNSPEC_VSUBW_S
  UNSPEC_VSUBW_U
  UNSPEC_VTBL
  UNSPEC_VTBX
  UNSPEC_VTRN1
  UNSPEC_VTRN2
  UNSPEC_VTST
  UNSPEC_VUZP1
  UNSPEC_VUZP2
  UNSPEC_VZIP1
  UNSPEC_VZIP2
  UNSPEC_MISALIGNED_ACCESS
  UNSPEC_VCLE
  UNSPEC_VCLT
  UNSPEC_NVRINTZ
  UNSPEC_NVRINTP
  UNSPEC_NVRINTM
  UNSPEC_NVRINTX
  UNSPEC_NVRINTA
  UNSPEC_NVRINTN
  UNSPEC_VQRDMLAH
  UNSPEC_VQRDMLSH
  UNSPEC_VRND
  UNSPEC_VRNDA
  UNSPEC_VRNDI
  UNSPEC_VRNDM
  UNSPEC_VRNDN
  UNSPEC_VRNDP
  UNSPEC_VRNDX
  UNSPEC_DOT_S
  UNSPEC_DOT_U
  UNSPEC_DOT_US
  UNSPEC_DOT_SU
  UNSPEC_VFML_LO
  UNSPEC_VFML_HI
  UNSPEC_VCADD90
  UNSPEC_VCADD270
  UNSPEC_VCMLA
  UNSPEC_VCMLA90
  UNSPEC_VCMLA180
  UNSPEC_VCMLA270
  UNSPEC_MATMUL_S
  UNSPEC_MATMUL_U
  UNSPEC_MATMUL_US
  UNSPEC_BFCVT
  UNSPEC_BFCVT_HIGH
  UNSPEC_BFMMLA
  UNSPEC_BFMAB
  UNSPEC_BFMAT
])
