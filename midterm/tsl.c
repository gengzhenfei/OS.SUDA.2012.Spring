enter_region:
    TSL REG, LOCK
    CMP REG, #0
    JNE enter_region
    RET

leave_region:
    MOVE LOCK, #0
    RET
