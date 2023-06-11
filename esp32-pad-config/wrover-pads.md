# ESP32 WROVER-B pad configuration

| Bus            | Schematic sig.      | Pad       | GPIO     | IO_MUX              | IO_MUX_PIN_CTRL      | Peripheral signal      |
|:---------------|:--------------------|:---------:|:--------:|:--------------------|:---------------------|:-----------------------|
| I2S            | BCLK                |    25     |    0     | Func1 (CLK_OUT1)    | I2S0_CLK->CLK_OUT1   | n/a                    |
| I2S            | LRCLK               |     8     |   32     | Func2 (GPIO)        | n/a                  | I2S0O_WS_out (26)      |
| I2S            | DIN                 |     9     |   33     | Func2 (GPIO)        | n/a                  | I2S0O_DATA_out0 (140)  |
| I2S            | /SD_MODE            |    12     |   27     | Func2 (GPIO)        | n/a                  | n/a                    |
| I2C            | SCL                 |    26     |    4     | Func2 (GPIO)        | n/a                  | I2CEXT0_SCL (29)       |
| I2C            | SDA                 |    29     |    5     | Func2 (GPIO)        | n/a                  | I2CEXT0_SDA (30)       |
| JTAG           | TMS                 |    13     |   14     | Func0 (MTMS)        | n/a                  | n/a                    |
| JTAG           | TDI                 |    14     |   12     | Func0 (MTDI)        | n/a                  | n/a                    |
| JTAG           | TCK                 |    16     |   13     | Func0 (MTCK)        | n/a                  | n/a                    |
| JTAG           | TDO                 |    23     |   15     | Func0 (MTDO)        | n/a                  | n/a                    |
| UART           | TXD                 |    35     |    1     | Func0 (U0TXD)       | n/a                  | n/a                    |
| UART           | RXD                 |    34     |    3     | Func0 (U0RXD)       | n/a                  | n/a                    |
| RELAY          | IO2                 |    24     |    2     | Func2 (GPIO)        | n/a                  | n/a                    |
| SDCARD         | SD0                 |    21     |    7     | Func0 (SD_DATA_0)   | n/a                  | n/a                    |
| SDCARD         | SD1                 |    22     |    8     | Func0 (SD_DATA_1)   | n/a                  | n/a                    |
| SDCARD         | SD2                 |    17     |    9     | Func0 (SD_DATA_2)   | n/a                  | n/a                    |
| SDCARD         | SD3                 |    18     |   10     | Func0 (SD_DATA_3)   | n/a                  | n/a                    |
| SDCARD         | CMD                 |    19     |   11     | Func0 (SD_CMD)      | n/a                  | n/a                    |
| SDCARD         | CLK                 |    20     |    6     | Func0 (SD_CLK)      | n/a                  | n/a                    |
| SDCARD         | DET_A               |     7     |   35     | Func2 (GPIO)        | n/a                  | n/a                    |
| PANEL          | S1_RED              |    36     |   22     | Func2 (GPIO)        | n/a                  | n/a                    |
| PANEL          | S1_GREEN            |    37     |   23     | Func2 (GPIO)        | n/a                  | n/a                    |
| PANEL          | S2_RED              |    30     |   18     | Func2 (GPIO)        | n/a                  | n/a                    |
| PANEL          | S2_GREEN            |    31     |   19     | Func2 (GPIO)        | n/a                  | n/a                    |
| PANEL          | S1_INPUT            |    33     |   21     | Func2 (GPIO)        | n/a                  | n/a                    |
| PANEL          | S2_INPUT            |    10     |   25     | Func2 (GPIO)        | n/a                  | n/a                    |
| LED            | RED                 |     5     |   39     | Func2 (GPIO)        | n/a                  | n/a                    |
| LED            | GREEN               |     4     |   36     | Func2 (GPIO)        | n/a                  | n/a                    |
