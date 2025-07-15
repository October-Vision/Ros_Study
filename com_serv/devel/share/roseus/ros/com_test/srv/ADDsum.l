;; Auto-generated. Do not edit!


(when (boundp 'com_test::ADDsum)
  (if (not (find-package "COM_TEST"))
    (make-package "COM_TEST"))
  (shadow 'ADDsum (find-package "COM_TEST")))
(unless (find-package "COM_TEST::ADDSUM")
  (make-package "COM_TEST::ADDSUM"))
(unless (find-package "COM_TEST::ADDSUMREQUEST")
  (make-package "COM_TEST::ADDSUMREQUEST"))
(unless (find-package "COM_TEST::ADDSUMRESPONSE")
  (make-package "COM_TEST::ADDSUMRESPONSE"))

(in-package "ROS")





(defclass com_test::ADDsumRequest
  :super ros::object
  :slots (_num1 _num2 ))

(defmethod com_test::ADDsumRequest
  (:init
   (&key
    ((:num1 __num1) 0)
    ((:num2 __num2) 0)
    )
   (send-super :init)
   (setq _num1 (round __num1))
   (setq _num2 (round __num2))
   self)
  (:num1
   (&optional __num1)
   (if __num1 (setq _num1 __num1)) _num1)
  (:num2
   (&optional __num2)
   (if __num2 (setq _num2 __num2)) _num2)
  (:serialization-length
   ()
   (+
    ;; int32 _num1
    4
    ;; int32 _num2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _num1
       (write-long _num1 s)
     ;; int32 _num2
       (write-long _num2 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _num1
     (setq _num1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _num2
     (setq _num2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass com_test::ADDsumResponse
  :super ros::object
  :slots (_sum ))

(defmethod com_test::ADDsumResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass com_test::ADDsum
  :super ros::object
  :slots ())

(setf (get com_test::ADDsum :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get com_test::ADDsum :datatype-) "com_test/ADDsum")
(setf (get com_test::ADDsum :request) com_test::ADDsumRequest)
(setf (get com_test::ADDsum :response) com_test::ADDsumResponse)

(defmethod com_test::ADDsumRequest
  (:response () (instance com_test::ADDsumResponse :init)))

(setf (get com_test::ADDsumRequest :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get com_test::ADDsumRequest :datatype-) "com_test/ADDsumRequest")
(setf (get com_test::ADDsumRequest :definition-)
      "#客户端请求的数据client(请求端)
int32 num1
int32 num2
---
#服务器响应发送的数据server(服务端)
int32 sum
")

(setf (get com_test::ADDsumResponse :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get com_test::ADDsumResponse :datatype-) "com_test/ADDsumResponse")
(setf (get com_test::ADDsumResponse :definition-)
      "#客户端请求的数据client(请求端)
int32 num1
int32 num2
---
#服务器响应发送的数据server(服务端)
int32 sum
")



(provide :com_test/ADDsum "4781436a0c2affec8025955a6041e481")


