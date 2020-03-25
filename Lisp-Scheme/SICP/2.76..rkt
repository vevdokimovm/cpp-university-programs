#lang racket

;; Message passing
(define (make-from-mag-ang r a)
  (define (dispatch op)
    (cond ((eq? op 'real-part)
           (* r (cos a)))
          ((eq? op 'imag-part)
           (* r (sin a)))
          ((eq? op 'magnitude) r)
          ((eq? op 'angel) a)
          (else (error "Неизвестная оп. -- MAKE-FROM-REAK-IMAG" op))))
  dispatch)