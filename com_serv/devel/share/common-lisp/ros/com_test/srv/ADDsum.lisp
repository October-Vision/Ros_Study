; Auto-generated. Do not edit!


(cl:in-package com_test-srv)


;//! \htmlinclude ADDsum-request.msg.html

(cl:defclass <ADDsum-request> (roslisp-msg-protocol:ros-message)
  ((num1
    :reader num1
    :initarg :num1
    :type cl:integer
    :initform 0)
   (num2
    :reader num2
    :initarg :num2
    :type cl:integer
    :initform 0))
)

(cl:defclass ADDsum-request (<ADDsum-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ADDsum-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ADDsum-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name com_test-srv:<ADDsum-request> is deprecated: use com_test-srv:ADDsum-request instead.")))

(cl:ensure-generic-function 'num1-val :lambda-list '(m))
(cl:defmethod num1-val ((m <ADDsum-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader com_test-srv:num1-val is deprecated.  Use com_test-srv:num1 instead.")
  (num1 m))

(cl:ensure-generic-function 'num2-val :lambda-list '(m))
(cl:defmethod num2-val ((m <ADDsum-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader com_test-srv:num2-val is deprecated.  Use com_test-srv:num2 instead.")
  (num2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ADDsum-request>) ostream)
  "Serializes a message object of type '<ADDsum-request>"
  (cl:let* ((signed (cl:slot-value msg 'num1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'num2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ADDsum-request>) istream)
  "Deserializes a message object of type '<ADDsum-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num1) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num2) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ADDsum-request>)))
  "Returns string type for a service object of type '<ADDsum-request>"
  "com_test/ADDsumRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ADDsum-request)))
  "Returns string type for a service object of type 'ADDsum-request"
  "com_test/ADDsumRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ADDsum-request>)))
  "Returns md5sum for a message object of type '<ADDsum-request>"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ADDsum-request)))
  "Returns md5sum for a message object of type 'ADDsum-request"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ADDsum-request>)))
  "Returns full string definition for message of type '<ADDsum-request>"
  (cl:format cl:nil "#客户端请求的数据client(请求端)~%int32 num1~%int32 num2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ADDsum-request)))
  "Returns full string definition for message of type 'ADDsum-request"
  (cl:format cl:nil "#客户端请求的数据client(请求端)~%int32 num1~%int32 num2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ADDsum-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ADDsum-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ADDsum-request
    (cl:cons ':num1 (num1 msg))
    (cl:cons ':num2 (num2 msg))
))
;//! \htmlinclude ADDsum-response.msg.html

(cl:defclass <ADDsum-response> (roslisp-msg-protocol:ros-message)
  ((sum
    :reader sum
    :initarg :sum
    :type cl:integer
    :initform 0))
)

(cl:defclass ADDsum-response (<ADDsum-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ADDsum-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ADDsum-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name com_test-srv:<ADDsum-response> is deprecated: use com_test-srv:ADDsum-response instead.")))

(cl:ensure-generic-function 'sum-val :lambda-list '(m))
(cl:defmethod sum-val ((m <ADDsum-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader com_test-srv:sum-val is deprecated.  Use com_test-srv:sum instead.")
  (sum m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ADDsum-response>) ostream)
  "Serializes a message object of type '<ADDsum-response>"
  (cl:let* ((signed (cl:slot-value msg 'sum)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ADDsum-response>) istream)
  "Deserializes a message object of type '<ADDsum-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sum) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ADDsum-response>)))
  "Returns string type for a service object of type '<ADDsum-response>"
  "com_test/ADDsumResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ADDsum-response)))
  "Returns string type for a service object of type 'ADDsum-response"
  "com_test/ADDsumResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ADDsum-response>)))
  "Returns md5sum for a message object of type '<ADDsum-response>"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ADDsum-response)))
  "Returns md5sum for a message object of type 'ADDsum-response"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ADDsum-response>)))
  "Returns full string definition for message of type '<ADDsum-response>"
  (cl:format cl:nil "#服务器响应发送的数据server(服务端)~%int32 sum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ADDsum-response)))
  "Returns full string definition for message of type 'ADDsum-response"
  (cl:format cl:nil "#服务器响应发送的数据server(服务端)~%int32 sum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ADDsum-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ADDsum-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ADDsum-response
    (cl:cons ':sum (sum msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ADDsum)))
  'ADDsum-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ADDsum)))
  'ADDsum-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ADDsum)))
  "Returns string type for a service object of type '<ADDsum>"
  "com_test/ADDsum")