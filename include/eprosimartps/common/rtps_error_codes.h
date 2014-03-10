/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima RTPS is licensed to you under the terms described in the
 * EPROSIMARTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file rtps_error_codes.h
 *	 Error codes.
 *  Created on: Feb 19, 2014
 *      Author: Gonzalo Rodriguez Canosa
 *      email:  gonzalorodriguez@eprosima.com
 */

#ifndef ERROR_CODES_H_
#define ERROR_CODES_H_

namespace eprosima{
namespace rtps{

#define ERR_CDRMESSAGE_BUFFER_FULL 101

#define ERR_MESSAGE_TOO_SHORT 201
#define ERR_MESSAGE_NOT_RTPS 202
#define ERR_MESSAGE_VERSION_UNSUPPORTED 203
#define ERR_SUBMSGHEADER_TOO_SHORT 204
#define ERR_SUBMSG_LENGTH_INVALID 205
#define ERR_MESSAGE_INCORRECT_HEADER 206

#define ERR_PARTICIPANT_INCORRECT_ENDPOINT_TYPE 301

}
}




#endif /* ERROR_CODES_H_ */