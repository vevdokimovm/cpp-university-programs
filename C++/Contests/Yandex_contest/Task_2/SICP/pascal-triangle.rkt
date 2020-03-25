#lang racket
(define (Pascal-triangle row pos)
  (if (or (> pos row) (= pos 0))
      "Incorrect input"
      (eval row pos)))
  
  
 (define (eval row pos)
   (cond ((= row pos 1) 1)
         ((or (= pos 0) (= pos (+ row 1))) 0)
         (else (+ (eval (- row 1) (- pos 1))
                  (eval (- row 1) pos)))))

(Pascal-triangle 5 3)