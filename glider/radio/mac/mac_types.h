#ifndef MAC_TYPES_H
#define MAC_TYPES_H

/** Broadcast address for use in address fields. */
static const uint64_t BROADCAST_ADDRESS = 0xffff;

/** Structure for the MAC frame control field. */
typedef struct frame_control_field
{
	uint16_t frame_type :3;
	uint16_t security_enabled :1;
	uint16_t frame_pending :1;
	uint16_t ar :1;
	uint16_t pan_id_compression :1;
	uint16_t reserved :3;
	uint16_t dest_addressing_mode :2;
	uint16_t frame_version :2;
	uint16_t src_addressing_mode :2;
} frame_control_field;

/** Structure for the superframe specification field. */
typedef struct superframe_specification_field
{
	uint16_t beacon_order :4;
	uint16_t superframe_order :4;
	uint16_t final_cap_slot :4;
	uint16_t battery_life_extension :1;
	uint16_t reserved :1;
	uint16_t pan_coordinator :1;
	uint16_t association_permit :1;
} superframe_specification_field;

/** Structure for the capability information field of association command frames. */
typedef struct capability_information_field
{
	uint8_t reserved_first :1;
	uint8_t device_type :1;
	uint8_t power_source :1;
	uint8_t receiver_on_when_idle :1;
	uint8_t reserved_second :2;
	uint8_t security_capability :1;
	uint8_t allocate_address :1;
} capability_information_field;

/** Types for MAC frames. */
typedef enum frame_type
{
	BEACON_FRAME = 0,
	DATA_FRAME = 1,
	ACK_FRAME = 2,
	CMD_FRAME = 3
} frame_type;

/** Types for the addressing mode. */
typedef enum addressing_mode
{
	NO_ADDRESS = 0,
	SHORT_ADDRESS = 2,
	EXTENDED_ADDRESS = 3
} addressing_mode;

/** Types for MAC command frames. */
typedef enum command_frame_identifier
{
	ASSOCIATION_REQUEST_COMMAND = 1,
	ASSOCIATION_RESPONSE_COMMAND,
	DISASSOCIATION_NOTIFICATION_COMMAND,
	DATA_REQUEST_COMMAND,
	PAN_ID_CONFLICT_NOTIFICATION_COMMAND,
	ORPHAN_NOTIFICATION_COMMAND,
	BEACON_REQUEST_COMMAND,
	COORDINATOR_REALIGNMENT_COMMAND,
} command_frame_identifier;

/** Values for the status of an association procedure. */
typedef enum association_status
{
	ASSOCIATION_SUCCESSFUL = 0,
	PAN_AT_CAPACITY,
	PAN_ACCESS_DENIED
} association_status;

/** Reasons for a disassociation. */
typedef enum disassociation_reason
{
	COORDINATOR_DRIVEN = 1,
	DEVICE_DRIVEN = 2
} disassociation_reason;

/** Types for MAC primitives from upper layer. */
typedef enum primitive_type
{
	DATA_REQUEST = 1,
	DATA_CONFIRM,
	DATA_INDICATION,
	UNKNOWN_PRIMITIVE
} primitive_type;

/** Types for status indications */
typedef enum status_type
{
	SUCCESS = 1,
	TRANSACTION_OVERFLOW,
	TRANSACTION_EXPIRED,
	CHANNEL_ACCESS_FAILURE,
	INVALID_ADDRESS,
	INVALID_GTS,
	NO_ACK,
	COUNTER_ERROR,
	FRAME_TOO_LONG,
	UNAVAILABLE_KEY,
	UNSUPPORTED_SECURITY,
	INVALID_PARAMETER
} status_type;

#endif
