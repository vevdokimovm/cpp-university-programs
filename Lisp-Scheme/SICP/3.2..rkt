#lang racket

(define (make-monitored proc)
  (let ((counter 0))
    (lambda (op)
      (cond ((eq? op 'how-many-calls?) counter)
            ((eq? op 'reset-count) (set! counter 0))
            (else (set! counter (+ counter 1)) (proc op))))))