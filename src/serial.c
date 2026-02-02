#include "serial.h"
#include "hardware/pio.h"
#include "psxSPI.pio.h"

static uint smCmdReader;
static uint smDatWriter;

static uint offsetCmdReader;
static uint offsetDatWriter;

void initPio() {
    smCmdReader = pio_claim_unused_sm(pio0, true);
	smDatWriter = pio_claim_unused_sm(pio0, true);

	dat_writer_program_init(pio0, smDatWriter, offsetDatWriter);
	cmd_reader_program_init(pio0, smCmdReader, offsetCmdReader);

	/* Enable all SM simultaneously */
	uint32_t smMask = (1 << smCmdReader) | (1 << smDatWriter);
	pio_enable_sm_mask_in_sync(pio0, smMask);
}

uint8_t read_byte_blocking() {
    return _read_byte_blocking(pio0, smCmdReader);
}

void write_byte_blocking(uint8_t byte) {
    _write_byte_blocking(pio0, smDatWriter, byte);
}