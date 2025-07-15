
(cl:in-package :asdf)

(defsystem "com_test-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ADDsum" :depends-on ("_package_ADDsum"))
    (:file "_package_ADDsum" :depends-on ("_package"))
  ))