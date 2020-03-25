#lang racket

(define (=zero? x) (apply-generic '=zero? x))

;; Scheme-numbers
(put '=zero? 'scheme-number
     (lambda (x) (= x 0)))

;; Rational
(put '=zero? 'rational
     (lambda (x) (= (numer x) 0)))

;; Complex
(put '=zero? 'complex
     (lambda (x) (and (= (real-part x) 0)
                      (= (imag-part x) 0))))